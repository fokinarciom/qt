/********************************************************************************
** Form generated from reading UI file 'visualcontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALCONTROL_H
#define UI_VISUALCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VisualControl
{
public:
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QWidget *VisualControl)
    {
        if (VisualControl->objectName().isEmpty())
            VisualControl->setObjectName(QString::fromUtf8("VisualControl"));
        VisualControl->resize(800, 600);
        checkBox = new QCheckBox(VisualControl);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(80, 130, 93, 26));
        checkBox_2 = new QCheckBox(VisualControl);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(230, 130, 93, 26));
        checkBox_3 = new QCheckBox(VisualControl);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(370, 130, 93, 26));
        checkBox_4 = new QCheckBox(VisualControl);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(520, 130, 93, 26));
        checkBox_5 = new QCheckBox(VisualControl);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(670, 130, 93, 26));
        pushButton = new QPushButton(VisualControl);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 210, 83, 29));
        pushButton_2 = new QPushButton(VisualControl);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 220, 83, 29));
        pushButton_3 = new QPushButton(VisualControl);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(390, 220, 83, 29));
        pushButton_4 = new QPushButton(VisualControl);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(540, 210, 83, 29));
        pushButton_5 = new QPushButton(VisualControl);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(700, 200, 83, 29));

        retranslateUi(VisualControl);

        QMetaObject::connectSlotsByName(VisualControl);
    } // setupUi

    void retranslateUi(QWidget *VisualControl)
    {
        VisualControl->setWindowTitle(QCoreApplication::translate("VisualControl", "VisualControl", nullptr));
        checkBox->setText(QCoreApplication::translate("VisualControl", "Pressed", nullptr));
        checkBox_2->setText(QCoreApplication::translate("VisualControl", "Pressed", nullptr));
        checkBox_3->setText(QCoreApplication::translate("VisualControl", "Pressed", nullptr));
        checkBox_4->setText(QCoreApplication::translate("VisualControl", "Pressed", nullptr));
        checkBox_5->setText(QCoreApplication::translate("VisualControl", "Pressed", nullptr));
        pushButton->setText(QCoreApplication::translate("VisualControl", "Press", nullptr));
        pushButton_2->setText(QCoreApplication::translate("VisualControl", "Press", nullptr));
        pushButton_3->setText(QCoreApplication::translate("VisualControl", "Press", nullptr));
        pushButton_4->setText(QCoreApplication::translate("VisualControl", "Press", nullptr));
        pushButton_5->setText(QCoreApplication::translate("VisualControl", "Press", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VisualControl: public Ui_VisualControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALCONTROL_H
