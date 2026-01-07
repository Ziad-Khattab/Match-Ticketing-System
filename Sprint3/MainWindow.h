#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTabWidget>
#include <vector>
#include "Match.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Fan Actions
    void handleBookTicket();
    void handleViewMyTickets();
    
    // Admin Actions
    void handleAddMatch();
    void handleDeleteMatch();

private:
    vector<Match> matches;

    // UI Elements
    QTabWidget *tabWidget;
    QTableWidget *fanTable;
    QTableWidget *adminTable;
    
    // Fan Inputs
    QLineEdit *fanNameInput;
    
    // Admin Inputs
    QLineEdit *adminMatchIdInput;
    QLineEdit *adminMatchNameInput;
    QLineEdit *adminCapacityInput;

    void setupUI();
    void loadDummyData();
    void refreshTables();
};

#endif