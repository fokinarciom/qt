/********************************************************************************
** Form generated from reading UI file 'fernleaf.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FERNLEAF_H
#define UI_FERNLEAF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FernLeaf
{
public:

    void setupUi(QWidget *FernLeaf)
    {
        if (FernLeaf->objectName().isEmpty())
            FernLeaf->setObjectName(QString::fromUtf8("FernLeaf"));
        FernLeaf->resize(800, 600);

        retranslateUi(FernLeaf);

        QMetaObject::connectSlotsByName(FernLeaf);
    } // setupUi

    void retranslateUi(QWidget *FernLeaf)
    {
        FernLeaf->setWindowTitle(QCoreApplication::translate("FernLeaf", "FernLeaf", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FernLeaf: public Ui_FernLeaf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FERNLEAF_H
