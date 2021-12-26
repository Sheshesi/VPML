#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>
#include <QStringList>
#include <QFile>
#include <QTextEdit>
#include <QTableWidgetItem>
#include "parametrs.h"
#include <QDebug>
#include <iostream>
#include <QDesktopServices>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QStringList typeParam;
    QStringList paramList;
    QStringList productsParam;
    QString timeParam;
    bool SWFind = false;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_takeparam_clicked();

    void recieveData(QString str);

    void on_findButton_clicked();

    void on_printAllTable_clicked();

    void on_openRecipe_clicked();

    void on_action_triggered();

    void on_openDatabase_triggered();

    void on_addInElect_triggered();

    void on_outfrom_triggered();

    void on_delFromElectMenu_triggered();

    void on_delFromElect_clicked();

    void on_openinfohelp_triggered();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db, db1;
    QSqlQuery *query, *mainquery;
    QSqlTableModel *model, *mainmodel;
    parametrs *par;
    QString electfilepath = "./electfile.txt";
    QFile electfile;



    int row;
};

#endif // MAINWINDOW_H
