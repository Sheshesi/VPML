#ifndef PARAMETRS_H
#define PARAMETRS_H

#include <QWidget>
#include <QTextCodec>
#include <QMessageBox>

namespace Ui {
class parametrs;
}

class parametrs : public QWidget
{
    Q_OBJECT

public:
    explicit parametrs(QWidget *parent = 0);
    ~parametrs();
signals:
    sendData(QString str);

private slots:
    void on_submitButton_clicked();

    void on_exitButton_clicked();

    void on_infoButt_clicked();

private:
    Ui::parametrs *ui;
};

#endif // PARAMETRS_H
