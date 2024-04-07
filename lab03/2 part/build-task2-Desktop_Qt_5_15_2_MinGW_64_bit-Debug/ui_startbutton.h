/********************************************************************************
** Form generated from reading UI file 'startbutton.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTBUTTON_H
#define UI_STARTBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Startbutton
{
public:

    void setupUi(QWidget *Startbutton)
    {
        if (Startbutton->objectName().isEmpty())
            Startbutton->setObjectName(QString::fromUtf8("Startbutton"));
        Startbutton->resize(800, 600);

        retranslateUi(Startbutton);

        QMetaObject::connectSlotsByName(Startbutton);
    } // setupUi

    void retranslateUi(QWidget *Startbutton)
    {
        Startbutton->setWindowTitle(QCoreApplication::translate("Startbutton", "Startbutton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Startbutton: public Ui_Startbutton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTBUTTON_H
