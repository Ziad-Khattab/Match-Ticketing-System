#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <vector>
#include "Match.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleBooking(); // Function to run when button is clicked

private:
    // GUI Elements
    QTableWidget *matchTable;
    QLineEdit *nameInput;
    QPushButton *bookButton;
    
    // Data
    vector<Match> matches;

    // Helper functions
    void setupUI();
    void refreshTable();
    void loadDummyData();
};

#endif