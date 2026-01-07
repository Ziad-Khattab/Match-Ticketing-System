#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QHeaderView>
#include <QLabel>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    loadDummyData();
    setupUI();
    refreshTables();
}

MainWindow::~MainWindow() {}

void MainWindow::loadDummyData() {
    matches.push_back(Match(1, "AHLY-ZAMALEK", 2));
    matches.push_back(Match(2, "REAL-BARCA", 5));
}

void MainWindow::setupUI() {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    tabWidget = new QTabWidget();
    
    // --- TAB 1: FAN ZONE ---
    QWidget *fanTab = new QWidget();
    QVBoxLayout *fanLayout = new QVBoxLayout(fanTab);
    
    fanTable = new QTableWidget();
    fanTable->setColumnCount(4);
    fanTable->setHorizontalHeaderLabels({"ID", "Match Code", "Capacity", "Booked"});
    fanTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    fanTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    fanTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QHBoxLayout *bookingLayout = new QHBoxLayout();
    fanNameInput = new QLineEdit();
    fanNameInput->setPlaceholderText("Enter Fan Name...");
    QPushButton *bookBtn = new QPushButton("Book Selected Match");
    QPushButton *myTicketsBtn = new QPushButton("View My Tickets");

    connect(bookBtn, &QPushButton::clicked, this, &MainWindow::handleBookTicket);
    connect(myTicketsBtn, &QPushButton::clicked, this, &MainWindow::handleViewMyTickets);

    bookingLayout->addWidget(fanNameInput);
    bookingLayout->addWidget(bookBtn);
    bookingLayout->addWidget(myTicketsBtn);

    fanLayout->addWidget(new QLabel("<b>Available Matches</b>"));
    fanLayout->addWidget(fanTable);
    fanLayout->addLayout(bookingLayout);
    tabWidget->addTab(fanTab, "Fan Zone");

    // --- TAB 2: ADMIN PANEL ---
    QWidget *adminTab = new QWidget();
    QVBoxLayout *adminLayout = new QVBoxLayout(adminTab);

    adminTable = new QTableWidget(); // Read-only view for admins to delete
    adminTable->setColumnCount(4);
    adminTable->setHorizontalHeaderLabels({"ID", "Match Code", "Capacity", "Booked"});
    adminTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    adminTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    adminTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QHBoxLayout *adminControlLayout = new QHBoxLayout();
    adminMatchIdInput = new QLineEdit(); adminMatchIdInput->setPlaceholderText("ID");
    adminMatchNameInput = new QLineEdit(); adminMatchNameInput->setPlaceholderText("Code");
    adminCapacityInput = new QLineEdit(); adminCapacityInput->setPlaceholderText("Cap");
    QPushButton *addMatchBtn = new QPushButton("Add Match");
    QPushButton *deleteMatchBtn = new QPushButton("Delete Selected");

    connect(addMatchBtn, &QPushButton::clicked, this, &MainWindow::handleAddMatch);
    connect(deleteMatchBtn, &QPushButton::clicked, this, &MainWindow::handleDeleteMatch);

    adminControlLayout->addWidget(adminMatchIdInput);
    adminControlLayout->addWidget(adminMatchNameInput);
    adminControlLayout->addWidget(adminCapacityInput);
    adminControlLayout->addWidget(addMatchBtn);

    adminLayout->addWidget(new QLabel("<b>Manage Matches</b>"));
    adminLayout->addWidget(adminTable);
    adminLayout->addLayout(adminControlLayout);
    adminLayout->addWidget(deleteMatchBtn);
    tabWidget->addTab(adminTab, "Admin Panel");

    mainLayout->addWidget(tabWidget);
    setWindowTitle("Sports Ticketing System");
    resize(700, 500);
}

void MainWindow::refreshTables() {
    // Helper to fill a table
    auto fill = [&](QTableWidget* t) {
        t->setRowCount(0);
        for(int i=0; i<matches.size(); i++) {
            t->insertRow(i);
            t->setItem(i, 0, new QTableWidgetItem(QString::number(matches[i].getMatchID())));
            t->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(matches[i].getMatchCode())));
            t->setItem(i, 2, new QTableWidgetItem(QString::number(matches[i].getCapacity())));
            t->setItem(i, 3, new QTableWidgetItem(QString::number(matches[i].getBookedCount())));
        }
    };
    fill(fanTable);
    fill(adminTable);
}

void MainWindow::handleBookTicket() {
    int row = fanTable->currentRow();
    if(row < 0) {
        QMessageBox::warning(this, "Error", "Select a match first!");
        return;
    }
    if(fanNameInput->text().isEmpty()) {
        QMessageBox::warning(this, "Error", "Enter fan name!");
        return;
    }

    if(matches[row].bookSeat(fanNameInput->text().toStdString())) {
        QMessageBox::information(this, "Success", "Ticket Booked!");
        refreshTables();
    } else {
        QMessageBox::critical(this, "Error", "Match is Full!");
    }
}

void MainWindow::handleViewMyTickets() {
    QString name = fanNameInput->text();
    if(name.isEmpty()) return;

    QString allTickets = "";
    for(auto& m : matches) {
        vector<string> t = m.getTicketsForFan(name.toStdString());
        for(const string& s : t) allTickets += QString::fromStdString(s) + "\n";
    }
    
    if(allTickets.isEmpty()) allTickets = "No tickets found.";
    QMessageBox::information(this, "My Tickets", allTickets);
}

void MainWindow::handleAddMatch() {
    int id = adminMatchIdInput->text().toInt();
    string code = adminMatchNameInput->text().toStdString();
    int cap = adminCapacityInput->text().toInt();

    if(id == 0 || code.empty() || cap == 0) return;

    matches.push_back(Match(id, code, cap));
    refreshTables();
    
    adminMatchIdInput->clear();
    adminMatchNameInput->clear();
    adminCapacityInput->clear();
}

void MainWindow::handleDeleteMatch() {
    int row = adminTable->currentRow();
    if(row >= 0) {
        matches.erase(matches.begin() + row);
        refreshTables();
    }
}