#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    loadDummyData(); // Load the Ahly/Zamalek matches
    setupUI();       // Draw the window
    refreshTable();  // Fill the table with data
}

MainWindow::~MainWindow() {}

void MainWindow::loadDummyData() {
    // Same data from your original main.cpp
    matches.push_back(Match(1, "AHLY-ZAMALEK", 2));
    matches.push_back(Match(2, "REAL-BARCA", 1));
}

void MainWindow::setupUI() {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // 1. Create Table
    matchTable = new QTableWidget();
    matchTable->setColumnCount(4);
    matchTable->setHorizontalHeaderLabels({"ID", "Match Code", "Capacity", "Booked"});
    matchTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    matchTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    matchTable->setEditTriggers(QAbstractItemView::NoEditTriggers); // Make read-only

    // 2. Input Section
    QLabel *nameLabel = new QLabel("Enter Fan Name:");
    nameInput = new QLineEdit();
    bookButton = new QPushButton("Book Selected Match");
    
    // Style the button
    bookButton->setStyleSheet("background-color: #4CAF50; color: white; padding: 10px;");

    // 3. Add to Layout
    layout->addWidget(new QLabel("<h3>Available Matches</h3>"));
    layout->addWidget(matchTable);
    layout->addWidget(nameLabel);
    layout->addWidget(nameInput);
    layout->addWidget(bookButton);

    // 4. Connect Button Click to Function
    connect(bookButton, &QPushButton::clicked, this, &MainWindow::handleBooking);

    setWindowTitle("Sports Match Ticketing System");
    resize(600, 400);
}

void MainWindow::refreshTable() {
    matchTable->setRowCount(0); // Clear table
    
    for(int i = 0; i < matches.size(); i++) {
        matchTable->insertRow(i);
        matchTable->setItem(i, 0, new QTableWidgetItem(QString::number(matches[i].getMatchID())));
        matchTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(matches[i].getMatchCode())));
        matchTable->setItem(i, 2, new QTableWidgetItem(QString::number(matches[i].getCapacity())));
        
        // Calculate availability for display
        QString status = QString::number(matches[i].getBookedCount()) + "/" + QString::number(matches[i].getCapacity());
        matchTable->setItem(i, 3, new QTableWidgetItem(status));
    }
}

void MainWindow::handleBooking() {
    // 1. Check if a row is selected
    int currentRow = matchTable->currentRow();
    if(currentRow < 0) {
        QMessageBox::warning(this, "Error", "Please select a match from the table.");
        return;
    }

    // 2. Check if name is entered
    QString fanName = nameInput->text();
    if(fanName.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a fan name.");
        return;
    }

    // 3. Try to book
    // Note: In this simple list, row index corresponds to vector index
    if(matches[currentRow].bookSeat(fanName.toStdString())) {
        QMessageBox::information(this, "Success", "Ticket Booked Successfully!");
        refreshTable(); // Update the table to show new booked count
        nameInput->clear();
    } else {
        QMessageBox::critical(this, "Failed", "Match is Full!");
    }
}