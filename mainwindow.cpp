#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    electfile.setFileName(electfilepath);
    par = new  parametrs();
    ui->takeparam->setToolTip("Открыть окно параметров");
    ui->textfieldForFind->setToolTip("Введите название блюда");
    ui->printAllTable->setToolTip("Сбросить вывод блюд");
    ui->findButton->setToolTip("Применить поиск по названию блюда");
    ui->recipeOut->setText("Сначала откройте рецепт");
    ui->delFromElect->setDisabled(true);
    ui->delFromElectMenu->setDisabled(true);
    connect(par,SIGNAL(sendData(QString)),this,SLOT(recieveData(QString)));
    connect(ui->action,SIGNAL(&QAction::triggered),this,SLOT(openDB()));


    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Sheshesi/Desktop/asd./recipes1.db");
    db.setUserName("user");

    if(!db.open())
    {
        qDebug() << db.lastError().text();
    }
    else
    {
        qDebug() << "Database was open";
    }




    query = new QSqlQuery(db);
    query->exec();
    model = new QSqlTableModel(this,db);
    model ->setTable("RecipesBook");


    model->select();

    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setColumnWidth(0,ui->tableView->width());

    ui->tableView->setColumnHidden(1,true);
    ui->tableView->setColumnHidden(2,true);
    ui->tableView->setColumnHidden(3,true);
    ui->tableView->setColumnHidden(4,true);
    ui->tableView->setColumnHidden(5,true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox mess;
    mess.setWindowTitle("Info");
    mess.setInformativeText(model->data(model->index(ui->tableView->currentIndex().row(),0)).toString());

    if(mess.informativeText() != "")
    {
        QStringList electlines;
        bool was = false;
        if(electfile.exists() && electfile.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&electfile);
            stream.setCodec("UTF-8");
            while(!electfile.atEnd())
            {
                electlines << electfile.readLine();
            }
            electfile.close();
        }
        foreach(QString s, electlines)
        {
            if(s == model->data(model->index(ui->tableView->currentIndex().row(),0)).toString().toUtf8()+QString("\n").toUtf8())
                was = true;
        }
        if(!was)
        {
            electfile.setFileName(electfilepath);
            if(electfile.open(QIODevice::Append))
            {
                QByteArray name_for_elect_recipe = model->data(model->index(ui->tableView->currentIndex().row(),0)).toByteArray();
                electfile.write(name_for_elect_recipe + "\n");
                electfile.close();
                mess.setText("В избранное был добавлен рецепт:");
                mess.exec();
            }
        }
        else
        {
            mess.setText("В избранном уже есть рецепт: ");
            mess.exec();
        }
    }
    else
    {
        mess.setText("Сначала выберите рецепт из списка.");
        mess.exec();
    }
}

void MainWindow::on_takeparam_clicked()
{
    par->show();
}

void MainWindow::recieveData(QString str)
{
    QString filter1;
    paramList = str.split(":");
    typeParam = paramList.at(0).split(",");
    timeParam = paramList.at(1);
    SWFind = paramList.at(3).toInt();
    productsParam = paramList.at(2).split(",");

    if(timeParam != "")
    {
        while(timeParam.length()<8)
        {
            timeParam = "0" + timeParam;
        }
    }
    else
        timeParam = "99999999";

    if(typeParam[0] != "")
    {
            for(int i = 0; i < typeParam.size();++i)
            {
                QString th = typeParam.at(i).toLower();
                th[0] = th[0].toUpper();
                if(!SWFind)
                {
                    for(int j = 0; j < productsParam.size();++j)
                    {
                        filter1 = filter1 + "type like '%" + typeParam.at(i).toLower() + "%'"+ QString(" AND time between '0' AND '%1'").arg(timeParam) + " AND products like '%" + productsParam.at(j).toLower() + "%' OR type like '%" + th + "%'" + QString(" AND time BETWEEN '0' AND '%1'").arg(timeParam) + " AND products like '%" + productsParam.at(j).toLower() + "%'";
                        if(j != productsParam.size()-1)
                                filter1 = filter1 + " OR ";
                    }
                    if(i != typeParam.size()-1)
                            filter1 = filter1 + " OR ";
                }
                else
                {
                    filter1 = filter1 + "type like '%" + typeParam.at(i).toLower() + "%'"+ QString(" AND time between '0' AND '%1'").arg(timeParam);
                    for(int j = 0; j < productsParam.size();++j)
                    {
                        filter1 = filter1 + " AND products like '%" + productsParam.at(j).toLower() + "%'";// OR type like '%" + th + "%'" + QString(" AND time BETWEEN '0' AND '%1'").arg(timeParam) + " AND products like '%" + productsParam.at(j).toLower() + "%'";
                    }
                    filter1 = filter1 + " OR type like '%" + th + "%'" + QString(" AND time BETWEEN '0' AND '%1'").arg(timeParam);
                    for(int j = 0; j < productsParam.size();++j)
                    {
                        filter1 = filter1 +" AND products like '%" + productsParam.at(j).toLower() + "%'";
                    }
                    if(i != typeParam.size()-1)
                        filter1 = filter1 + " OR ";
                }


            }
//            if(timeParam != "" || productsParam.at(0) != "")
//                filter1 = filter1 + " AND ";
    }

    if(typeParam.at(0) == "")
    {
        filter1 = filter1 + QString("time BETWEEN '%1' AND '%2'").arg(0,timeParam);
        if(productsParam.at(0) != "")
            filter1 = filter1 + " AND ";
    }
    if(typeParam.at(0) == "" && productsParam.at(0) != "")
        for(int i = 0; i < productsParam.size();++i)
        {
            filter1 = filter1 + "products like '%" + productsParam.at(i).toLower() + "%'";
            if(i != productsParam.size()-1)
             {   if(!SWFind)
                {    filter1 = filter1 + " OR ";}
                else
                {   filter1 = filter1 + " AND ";}
            }
        }
        //ui->recipeOut->setText(filter1);
    paramList.clear();
    typeParam.clear();
    timeParam = "";
    productsParam.clear();

    model->setFilter(filter1);

}

void MainWindow::on_findButton_clicked()
{
    if(ui->textfieldForFind->text() != "")
    {
        QString searchPar = ui->textfieldForFind->text().toLower();

        QString searchParam = "name = '" + searchPar;
        searchPar[0] = searchPar[0].toUpper();
        searchParam = searchParam + "' OR name = '" + searchPar + "'";
        qDebug() << searchParam;
        model->setFilter(searchParam);
        ui->tableView->update();
    }
}

void MainWindow::on_printAllTable_clicked()
{
    model->setFilter(QString());
    ui->tableView->update();
    ui->pushButton->setDisabled(false);
    ui->addInElect->setDisabled(false);
    ui->delFromElect->setDisabled(true);
    ui->delFromElectMenu->setDisabled(true);
}

void MainWindow::on_openRecipe_clicked()
{
   QString viewProd = "Ингридиенты: " + model->data(model->index(ui->tableView->currentIndex().row(),2)).toString() + ".";
   QString viewTime = model->data(model->index(ui->tableView->currentIndex().row(),3)).toString();
   int der=0;
   while(viewTime[der] == '0')
   {
       der++;
   }
   QString viewCorrectTime;
   while(der < viewTime.length())
   {
       viewCorrectTime += viewTime[der];
       der++;
   }
   viewCorrectTime = "Время приготовления: " + viewCorrectTime + " минут";
   QString viewPixmap = "C:\\Users\\Sheshesi\\Desktop\\asd" + model->data(model->index(ui->tableView->currentIndex().row(),4)).toString();
   QString viewDesc = "Описание: " + model->data(model->index(ui->tableView->currentIndex().row(),5)).toString();
   ui->photolabel->setPixmap(QPixmap(QString(viewPixmap)));
   ui->recipeOut->setText(viewProd + "\n\n" + viewCorrectTime + "\n\n" + viewDesc);
   qDebug() << viewProd.toUtf8() << endl << viewPixmap;
}


void MainWindow::on_action_triggered()
{
    electfile.setFileName(electfilepath);
    if(electfile.exists())
    {
        if(electfile.open(QIODevice::ReadOnly))
        {
            QTextStream out(&electfile);
            out.setCodec("Unicode");
            QString idnumbers;
            while(!electfile.atEnd())
            {
                idnumbers = idnumbers + electfile.readLine();
            }
            QStringList electList = idnumbers.split("\n");
            QString elect;
            for(int i = 0; i < electList.size()-1;++i)
            {
                elect = elect + "name = '" + electList.at(i) + "'";
                if(i != electList.size()-2)
                    elect = elect + " OR ";
            }
            model->setFilter(elect);
            ui->tableView->update();
            electfile.close();
            ui->pushButton->setDisabled(true);
            ui->addInElect->setDisabled(true);
            ui->delFromElect->setDisabled(false);
            ui->delFromElectMenu->setDisabled(false);
        }
        else
            qDebug() << "Elect File was not open";

    }
    else
    {
        QMessageBox mess;
        mess.setWindowTitle("Предупреждение");
        mess.setText("Внимание!");
        mess.setInformativeText("Избранное пусто");
        mess.exec();
    }
}

void MainWindow::on_openDatabase_triggered()
{
    model->setFilter(QString());
    ui->tableView->update();
    ui->pushButton->setDisabled(false);
    ui->addInElect->setDisabled(false);
    ui->delFromElect->setDisabled(true);
    ui->delFromElectMenu->setDisabled(true);
}

void MainWindow::on_addInElect_triggered()
{
    QMessageBox mess;
    mess.setWindowTitle("Info");
    mess.setInformativeText(model->data(model->index(ui->tableView->currentIndex().row(),0)).toString());

    if(mess.informativeText() != "")
    {
        QStringList electlines;
        bool was = false;
        if(electfile.exists() && electfile.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&electfile);
            stream.setCodec("UTF-8");
            while(!electfile.atEnd())
            {
                electlines << electfile.readLine();
            }
            electfile.close();
        }
        foreach(QString s, electlines)
        {
            if(s == model->data(model->index(ui->tableView->currentIndex().row(),0)).toString().toUtf8()+QString("\n").toUtf8())
                was = true;
        }
        if(!was)
        {
            electfile.setFileName(electfilepath);
            if(electfile.open(QIODevice::Append))
            {
                QByteArray name_for_elect_recipe = model->data(model->index(ui->tableView->currentIndex().row(),0)).toByteArray();
                electfile.write(name_for_elect_recipe + "\n");
                electfile.close();
                mess.setText("В избранное был добавлен рецепт:");
                mess.exec();
            }
        }
        else
        {
            mess.setText("В избранном уже есть рецепт: ");
            mess.exec();
        }
    }
    else
    {
        mess.setText("Сначала выберите рецепт из списка.");
        mess.exec();
    }

}

void MainWindow::on_outfrom_triggered()
{
    close();
}

void MainWindow::on_delFromElectMenu_triggered()
{
    QMessageBox mess;
    mess.setWindowTitle("Info");
    mess.setInformativeText(model->data(model->index(ui->tableView->currentIndex().row(),0)).toString());
    if(mess.informativeText() != "")
    {
        QStringList electlines;
        if(electfile.exists() && electfile.open(QIODevice::ReadOnly))
        {
            while(!electfile.atEnd())
            {
                electlines << electfile.readLine();
            }
            electfile.close();
        }
        if(electfile.exists() && electfile.open(QIODevice::WriteOnly))
        {
            for(int i = 0; i < electlines.size();++i)
            {
                if(electlines[i] == model->data(model->index(ui->tableView->currentIndex().row(),0)).toString() + "\n")
                    electlines.removeAt(i);
            }
            QTextStream stream(&electfile);
            stream.setCodec("UTF-8");
            foreach(QString s, electlines)
            {
                stream << s;
            }
           electfile.close();
        }
        if(electfile.open(QIODevice::ReadOnly))
        {
            QTextStream out(&electfile);
            out.setCodec("Unicode");
            QString idnumbers;
            while(!electfile.atEnd())
            {
                idnumbers = idnumbers + electfile.readLine();
            }
            QStringList electList = idnumbers.split("\n");
            QString elect;
            for(int i = 0; i < electList.size()-1;++i)
            {
                elect = elect + "name = '" + electList.at(i) + "'";
                if(i != electList.size()-2)
                    elect = elect + " OR ";
            }
            model->setFilter(elect);
            ui->tableView->update();
            electfile.close();
        }
        mess.setText("Следующий рецерт был удалён: ");
        mess.exec();
    }
    else
    {
        mess.setText("Сначала выберете элемент для удаления");
        mess.setInformativeText("");
        mess.exec();
    }
}

void MainWindow::on_delFromElect_clicked()
{
    QMessageBox mess;
    mess.setWindowTitle("Info");
    mess.setInformativeText(model->data(model->index(ui->tableView->currentIndex().row(),0)).toString());
    if(mess.informativeText() != "")
    {
        QStringList electlines;
        if(electfile.exists() && electfile.open(QIODevice::ReadOnly))
        {
            while(!electfile.atEnd())
            {
                electlines << electfile.readLine();
            }
            electfile.close();
        }
        if(electfile.exists() && electfile.open(QIODevice::WriteOnly))
        {
            for(int i = 0; i < electlines.size();++i)
            {
                if(electlines[i] == model->data(model->index(ui->tableView->currentIndex().row(),0)).toString() + "\n")
                    electlines.removeAt(i);
            }
            QTextStream stream(&electfile);
            stream.setCodec("UTF-8");
            foreach(QString s, electlines)
            {
                stream << s;
            }
           electfile.close();
        }
        if(electfile.open(QIODevice::ReadOnly))
        {
            QTextStream out(&electfile);
            out.setCodec("Unicode");
            QString idnumbers;
            while(!electfile.atEnd())
            {
                idnumbers = idnumbers + electfile.readLine();
            }
            QStringList electList = idnumbers.split("\n");
            QString elect;
            for(int i = 0; i < electList.size()-1;++i)
            {
                elect = elect + "name = '" + electList.at(i) + "'";
                if(i != electList.size()-2)
                    elect = elect + " OR ";
            }
            model->setFilter(elect);
            ui->tableView->update();
            electfile.close();
        }
        mess.setText("Следующий рецерт был удалён: ");
        mess.exec();
    }
    else
    {
        mess.setText("Сначала выберете элемент для удаления");
        mess.setInformativeText("");
        mess.exec();
    }
}

void MainWindow::on_openinfohelp_triggered()
{
    QString path = "C:\\Users\\Sheshesi\\Desktop\\asd\\help\\inf.html";
    QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}
