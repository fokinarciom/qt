/********************************************************************************
** Form generated from reading UI file 'deservedclicker.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESERVEDCLICKER_H
#define UI_DESERVEDCLICKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeservedClicker
{
public:
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QProgressBar *progressBar;

    void setupUi(QWidget *DeservedClicker)
    {
        if (DeservedClicker->objectName().isEmpty())
            DeservedClicker->setObjectName(QString::fromUtf8("DeservedClicker"));
        DeservedClicker->resize(800, 600);
        spinBox = new QSpinBox(DeservedClicker);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(50, 120, 81, 51));
        spinBox->setMaximum(100);
        spinBox->setSingleStep(1);
        pushButton = new QPushButton(DeservedClicker);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 270, 111, 61));
        progressBar = new QProgressBar(DeservedClicker);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(340, 280, 391, 111));
        progressBar->setValue(0);

        retranslateUi(DeservedClicker);

        QMetaObject::connectSlotsByName(DeservedClicker);
    } // setupUi

    void retranslateUi(QWidget *DeservedClicker)
    {
        DeservedClicker->setWindowTitle(QCoreApplication::translate("DeservedClicker", "DeservedClicker", nullptr));
        pushButton->setText(QCoreApplication::translate("DeservedClicker", "Push", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeservedClicker: public Ui_DeservedClicker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESERVEDCLICKER_H
