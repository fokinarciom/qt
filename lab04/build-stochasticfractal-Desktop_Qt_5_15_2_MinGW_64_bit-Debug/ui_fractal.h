/********************************************************************************
** Form generated from reading UI file 'fractal.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRACTAL_H
#define UI_FRACTAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fractal
{
public:

    void setupUi(QWidget *Fractal)
    {
        if (Fractal->objectName().isEmpty())
            Fractal->setObjectName(QString::fromUtf8("Fractal"));
        Fractal->resize(800, 600);

        retranslateUi(Fractal);

        QMetaObject::connectSlotsByName(Fractal);
    } // setupUi

    void retranslateUi(QWidget *Fractal)
    {
        Fractal->setWindowTitle(QCoreApplication::translate("Fractal", "Fractal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fractal: public Ui_Fractal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRACTAL_H
