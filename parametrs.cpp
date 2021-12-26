#include "parametrs.h"
#include "ui_parametrs.h"
#include "mainwindow.h"

parametrs::parametrs(QWidget *parent) : QWidget(parent),
    ui(new Ui::parametrs)
{

    ui->setupUi(this);
    ui->checkBox->setToolTip("Все ингридиенты в одном блюде");
    ui->infoButt->setToolTip("Посмотреть возможные типы");

}

parametrs::~parametrs()
{
    delete ui;
}

void parametrs::on_submitButton_clicked()
{
    QString params;
    if(ui->checkBox->isChecked())
        params = ui->typeLineEdit->text() + ":" + ui->timeLineEdit->text() + ":" + ui->productsLineEdit->text() + ":1";
    else
        params = ui->typeLineEdit->text() + ":" + ui->timeLineEdit->text() + ":" + ui->productsLineEdit->text() + ":0";
    ui->typeLineEdit->setText("");
    ui->timeLineEdit->setText("");
    ui->productsLineEdit->setText("");
    emit sendData(params);
    close();
}

void parametrs::on_exitButton_clicked()
{
    close();
}

void parametrs::on_infoButt_clicked()
{
    QMessageBox mess;
    mess.setText("Возможны следующие типы:");
    mess.setInformativeText("-Горячее\n-холодное\n-салат\n-напитки\n-второе\n-первое\n-завтрак\n-быстро\n-суп\n-мясное\n-из теста\n-закуска");
    mess.exec();
}
