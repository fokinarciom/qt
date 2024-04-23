/********************************************************************************
** Form generated from reading UI file 'snowflake.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNOWFLAKE_H
#define UI_SNOWFLAKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Snowflake
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Snowflake)
    {
        if (Snowflake->objectName().isEmpty())
            Snowflake->setObjectName(QString::fromUtf8("Snowflake"));
        Snowflake->resize(800, 600);
        centralwidget = new QWidget(Snowflake);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Snowflake->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Snowflake);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Snowflake->setMenuBar(menubar);
        statusbar = new QStatusBar(Snowflake);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Snowflake->setStatusBar(statusbar);

        retranslateUi(Snowflake);

        QMetaObject::connectSlotsByName(Snowflake);
    } // setupUi

    void retranslateUi(QMainWindow *Snowflake)
    {
        Snowflake->setWindowTitle(QCoreApplication::translate("Snowflake", "Snowflake", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Snowflake: public Ui_Snowflake {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNOWFLAKE_H
