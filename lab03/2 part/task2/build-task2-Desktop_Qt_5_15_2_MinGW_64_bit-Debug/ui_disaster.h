/********************************************************************************
** Form generated from reading UI file 'disaster.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISASTER_H
#define UI_DISASTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Disaster
{
public:

    void setupUi(QWidget *Disaster)
    {
        if (Disaster->objectName().isEmpty())
            Disaster->setObjectName(QString::fromUtf8("Disaster"));
        Disaster->resize(800, 600);

        retranslateUi(Disaster);

        QMetaObject::connectSlotsByName(Disaster);
    } // setupUi

    void retranslateUi(QWidget *Disaster)
    {
        Disaster->setWindowTitle(QCoreApplication::translate("Disaster", "Disaster", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Disaster: public Ui_Disaster {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISASTER_H
