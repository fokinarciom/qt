/********************************************************************************
** Form generated from reading UI file 'histogram.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAM_H
#define UI_HISTOGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Histogram
{
public:

    void setupUi(QWidget *Histogram)
    {
        if (Histogram->objectName().isEmpty())
            Histogram->setObjectName(QString::fromUtf8("Histogram"));
        Histogram->resize(800, 600);

        retranslateUi(Histogram);

        QMetaObject::connectSlotsByName(Histogram);
    } // setupUi

    void retranslateUi(QWidget *Histogram)
    {
        Histogram->setWindowTitle(QCoreApplication::translate("Histogram", "Histogram", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Histogram: public Ui_Histogram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAM_H
