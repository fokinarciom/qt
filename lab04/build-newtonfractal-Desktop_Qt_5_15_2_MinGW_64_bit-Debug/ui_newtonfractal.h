/********************************************************************************
** Form generated from reading UI file 'newtonfractal.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWTONFRACTAL_H
#define UI_NEWTONFRACTAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewtonFractal
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *NewtonFractal)
    {
        if (NewtonFractal->objectName().isEmpty())
            NewtonFractal->setObjectName(QString::fromUtf8("NewtonFractal"));
        NewtonFractal->resize(800, 600);
        centralwidget = new QWidget(NewtonFractal);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        NewtonFractal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NewtonFractal);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        NewtonFractal->setMenuBar(menubar);
        statusbar = new QStatusBar(NewtonFractal);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        NewtonFractal->setStatusBar(statusbar);

        retranslateUi(NewtonFractal);

        QMetaObject::connectSlotsByName(NewtonFractal);
    } // setupUi

    void retranslateUi(QMainWindow *NewtonFractal)
    {
        NewtonFractal->setWindowTitle(QCoreApplication::translate("NewtonFractal", "NewtonFractal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewtonFractal: public Ui_NewtonFractal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWTONFRACTAL_H
