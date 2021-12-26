/********************************************************************************
** Form generated from reading UI file 'infotext.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOTEXT_H
#define UI_INFOTEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoText
{
public:

    void setupUi(QWidget *InfoText)
    {
        if (InfoText->objectName().isEmpty())
            InfoText->setObjectName(QStringLiteral("InfoText"));
        InfoText->resize(400, 300);

        retranslateUi(InfoText);

        QMetaObject::connectSlotsByName(InfoText);
    } // setupUi

    void retranslateUi(QWidget *InfoText)
    {
        InfoText->setWindowTitle(QApplication::translate("InfoText", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoText: public Ui_InfoText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOTEXT_H
