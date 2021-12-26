/********************************************************************************
** Form generated from reading UI file 'parametrs.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETRS_H
#define UI_PARAMETRS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_parametrs
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *submitButton;
    QPushButton *exitButton;
    QLineEdit *typeLineEdit;
    QLineEdit *timeLineEdit;
    QLineEdit *productsLineEdit;
    QCheckBox *checkBox;
    QPushButton *infoButt;

    void setupUi(QWidget *parametrs)
    {
        if (parametrs->objectName().isEmpty())
            parametrs->setObjectName(QStringLiteral("parametrs"));
        parametrs->resize(456, 192);
        label_2 = new QLabel(parametrs);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 101, 21));
        label_3 = new QLabel(parametrs);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 80, 231, 21));
        label_4 = new QLabel(parametrs);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 110, 131, 21));
        horizontalLayoutWidget = new QWidget(parametrs);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 150, 431, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        submitButton = new QPushButton(horizontalLayoutWidget);
        submitButton->setObjectName(QStringLiteral("submitButton"));

        horizontalLayout->addWidget(submitButton);

        exitButton = new QPushButton(horizontalLayoutWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        horizontalLayout->addWidget(exitButton);

        typeLineEdit = new QLineEdit(parametrs);
        typeLineEdit->setObjectName(QStringLiteral("typeLineEdit"));
        typeLineEdit->setGeometry(QRect(250, 50, 191, 22));
        timeLineEdit = new QLineEdit(parametrs);
        timeLineEdit->setObjectName(QStringLiteral("timeLineEdit"));
        timeLineEdit->setGeometry(QRect(250, 80, 191, 22));
        productsLineEdit = new QLineEdit(parametrs);
        productsLineEdit->setObjectName(QStringLiteral("productsLineEdit"));
        productsLineEdit->setGeometry(QRect(250, 110, 191, 22));
        checkBox = new QCheckBox(parametrs);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(140, 110, 81, 20));
        infoButt = new QPushButton(parametrs);
        infoButt->setObjectName(QStringLiteral("infoButt"));
        infoButt->setGeometry(QRect(215, 53, 16, 16));
        infoButt->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral("../build-FoodBeta-Desktop_Qt_5_10_0_MinGW_32bit-Debug/images/ques.png"), QSize(), QIcon::Normal, QIcon::Off);
        infoButt->setIcon(icon);
        infoButt->setIconSize(QSize(14, 14));

        retranslateUi(parametrs);

        QMetaObject::connectSlotsByName(parametrs);
    } // setupUi

    void retranslateUi(QWidget *parametrs)
    {
        parametrs->setWindowTitle(QApplication::translate("parametrs", "\320\236\320\272\320\275\320\276 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\276\320\262", nullptr));
        label_2->setText(QApplication::translate("parametrs", "\320\242\320\270\320\277 \320\261\320\273\321\216\320\264\320\260", nullptr));
        label_3->setText(QApplication::translate("parametrs", "\320\222\321\200\320\265\320\274\321\217 \320\277\321\200\320\270\320\263\320\276\321\202\320\276\320\262\320\273\320\265\320\275\320\270\321\217 \320\264\320\276 (\320\262 \320\274\320\270\320\275\321\203\321\202\320\260\321\205)", nullptr));
        label_4->setText(QApplication::translate("parametrs", "\320\222\320\270\320\264\321\213 \320\270\320\275\320\263\321\200\320\270\320\264\320\270\320\265\320\275\321\202\320\276\320\262", nullptr));
        submitButton->setText(QApplication::translate("parametrs", "Ok", nullptr));
        exitButton->setText(QApplication::translate("parametrs", "Cancel", nullptr));
        checkBox->setText(QApplication::translate("parametrs", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214", nullptr));
        infoButt->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class parametrs: public Ui_parametrs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETRS_H
