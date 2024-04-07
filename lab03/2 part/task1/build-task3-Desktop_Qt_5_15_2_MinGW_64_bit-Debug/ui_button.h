/********************************************************************************
** Form generated from reading UI file 'button.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTON_H
#define UI_BUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Button
{
public:

    void setupUi(QWidget *Button)
    {
        if (Button->objectName().isEmpty())
            Button->setObjectName(QString::fromUtf8("Button"));
        Button->resize(800, 600);

        retranslateUi(Button);

        QMetaObject::connectSlotsByName(Button);
    } // setupUi

    void retranslateUi(QWidget *Button)
    {
        Button->setWindowTitle(QCoreApplication::translate("Button", "Button", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Button: public Ui_Button {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTON_H
