/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *openDatabase;
    QAction *outfrom;
    QAction *action;
    QAction *addInElect;
    QAction *delFromElectMenu;
    QAction *openinfohelp;
    QWidget *centralWidget;
    QPushButton *findButton;
    QTextEdit *recipeOut;
    QTableView *tableView;
    QPushButton *pushButton;
    QLabel *photolabel;
    QPushButton *takeparam;
    QLineEdit *textfieldForFind;
    QPushButton *printAllTable;
    QPushButton *openRecipe;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *delFromElect;
    QMenuBar *menuBar;
    QMenu *MainMenu;
    QMenu *infohelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(640, 629);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral("../build-FoodBeta-Desktop_Qt_5_10_0_MinGW_32bit-Debug/images/WIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        openDatabase = new QAction(MainWindow);
        openDatabase->setObjectName(QStringLiteral("openDatabase"));
        outfrom = new QAction(MainWindow);
        outfrom->setObjectName(QStringLiteral("outfrom"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        addInElect = new QAction(MainWindow);
        addInElect->setObjectName(QStringLiteral("addInElect"));
        delFromElectMenu = new QAction(MainWindow);
        delFromElectMenu->setObjectName(QStringLiteral("delFromElectMenu"));
        openinfohelp = new QAction(MainWindow);
        openinfohelp->setObjectName(QStringLiteral("openinfohelp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        findButton = new QPushButton(centralWidget);
        findButton->setObjectName(QStringLiteral("findButton"));
        findButton->setGeometry(QRect(10, 40, 91, 31));
        recipeOut = new QTextEdit(centralWidget);
        recipeOut->setObjectName(QStringLiteral("recipeOut"));
        recipeOut->setGeometry(QRect(310, 330, 321, 241));
        QFont font;
        font.setPointSize(12);
        recipeOut->setFont(font);
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 80, 291, 341));
        tableView->setSortingEnabled(false);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 480, 291, 41));
        photolabel = new QLabel(centralWidget);
        photolabel->setObjectName(QStringLiteral("photolabel"));
        photolabel->setGeometry(QRect(310, 80, 321, 231));
        photolabel->setFrameShape(QFrame::StyledPanel);
        photolabel->setPixmap(QPixmap(QString::fromUtf8("images/nonephoto.jpg")));
        photolabel->setScaledContents(true);
        takeparam = new QPushButton(centralWidget);
        takeparam->setObjectName(QStringLiteral("takeparam"));
        takeparam->setGeometry(QRect(110, 40, 91, 31));
        textfieldForFind = new QLineEdit(centralWidget);
        textfieldForFind->setObjectName(QStringLiteral("textfieldForFind"));
        textfieldForFind->setGeometry(QRect(130, 0, 501, 31));
        printAllTable = new QPushButton(centralWidget);
        printAllTable->setObjectName(QStringLiteral("printAllTable"));
        printAllTable->setGeometry(QRect(210, 40, 91, 31));
        openRecipe = new QPushButton(centralWidget);
        openRecipe->setObjectName(QStringLiteral("openRecipe"));
        openRecipe->setGeometry(QRect(10, 430, 291, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 310, 191, 16));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 50, 111, 16));
        label_2->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 0, 151, 31));
        label_3->setFont(font1);
        delFromElect = new QPushButton(centralWidget);
        delFromElect->setObjectName(QStringLiteral("delFromElect"));
        delFromElect->setGeometry(QRect(10, 530, 291, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 21));
        MainMenu = new QMenu(menuBar);
        MainMenu->setObjectName(QStringLiteral("MainMenu"));
        infohelp = new QMenu(menuBar);
        infohelp->setObjectName(QStringLiteral("infohelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(MainMenu->menuAction());
        menuBar->addAction(infohelp->menuAction());
        MainMenu->addAction(openDatabase);
        MainMenu->addAction(action);
        MainMenu->addAction(addInElect);
        MainMenu->addAction(delFromElectMenu);
        MainMenu->addAction(outfrom);
        infohelp->addAction(openinfohelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\232\320\275\320\270\320\263\320\260 \321\200\320\265\321\206\320\265\320\277\321\202\320\276\320\262", nullptr));
        openDatabase->setText(QApplication::translate("MainWindow", "\320\222\321\201\320\265 \320\261\320\273\321\216\320\264\320\260", nullptr));
#ifndef QT_NO_TOOLTIP
        openDatabase->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\320\236\321\202\320\272\321\200\321\213\320\262\320\260\320\265\321\202 \321\201\320\277\320\270\321\201\320\276\320\272 \320\262\321\201\320\265\321\205 \321\200\320\265\321\206\320\265\320\277\321\202\320\276\320\262</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        openDatabase->setStatusTip(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\261\320\260\320\267\321\203 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        openDatabase->setWhatsThis(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\261\320\260\320\267\321\203 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_SHORTCUT
        openDatabase->setShortcut(QApplication::translate("MainWindow", "Alt+O", nullptr));
#endif // QT_NO_SHORTCUT
        outfrom->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
#ifndef QT_NO_TOOLTIP
        outfrom->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\320\227\320\260\320\272\321\200\321\213\320\262\320\260\320\265\321\202 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        outfrom->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+E", nullptr));
#endif // QT_NO_SHORTCUT
        action->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
#ifndef QT_NO_TOOLTIP
        action->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\320\236\321\202\320\272\321\200\321\213\320\262\320\260\320\265\321\202 \321\201\320\277\320\270\321\201\320\276\320\272 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\321\213\321\205 \320\261\320\273\321\216\320\264</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action->setShortcut(QApplication::translate("MainWindow", "Alt+I", nullptr));
#endif // QT_NO_SHORTCUT
        addInElect->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
#ifndef QT_NO_TOOLTIP
        addInElect->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\320\224\320\276\320\261\320\260\320\262\320\273\321\217\320\265\321\202 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\321\213\320\271 \321\200\320\265\321\206\320\265\320\277\321\202 \320\262 \321\201\320\277\320\270\321\201\320\272\320\265 \320\262\321\201\320\265\321\205 \320\261\320\273\321\216\320\264 \320\262 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        addInElect->setShortcut(QApplication::translate("MainWindow", "Alt+A", nullptr));
#endif // QT_NO_SHORTCUT
        delFromElectMenu->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\270\320\267 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276", nullptr));
#ifndef QT_NO_TOOLTIP
        delFromElectMenu->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\320\243\320\264\320\260\320\273\321\217\320\265\321\202 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\321\213\320\271 \321\200\320\265\321\206\320\265\320\277\321\202 \320\270\320\267 \321\201\320\277\320\270\321\201\320\272\320\260 \320\270\320\267\320\261\321\200\320\260\320\275\320\275\321\213\321\205 \321\200\320\265\321\206\320\265\320\277\321\202\320\276\320\262</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        delFromElectMenu->setShortcut(QApplication::translate("MainWindow", "Alt+D", nullptr));
#endif // QT_NO_SHORTCUT
        openinfohelp->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\201\320\277\321\200\320\260\320\262\320\272\321\203", nullptr));
        findButton->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        recipeOut->setDocumentTitle(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\320\276\320\271\321\202\320\265 \321\200\320\265\321\206\320\265\320\277\321\202", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262\n"
"\320\270\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        photolabel->setText(QString());
#ifndef QT_NO_WHATSTHIS
        takeparam->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        takeparam->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        printAllTable->setText(QApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        openRecipe->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\200\320\265\321\206\320\265\320\277\321\202", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \321\200\320\265\321\206\320\265\320\277\321\202\320\260", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\244\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\321\217", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\261\320\273\321\216\320\264\320\260", nullptr));
        delFromElect->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\270\320\267 \n"
"\320\270\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276", nullptr));
        MainMenu->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
        infohelp->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
