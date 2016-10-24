/********************************************************************************
** Form generated from reading UI file 'eachpath.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EACHPATH_H
#define UI_EACHPATH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EachPath
{
public:

    void setupUi(QWidget *EachPath)
    {
        if (EachPath->objectName().isEmpty())
            EachPath->setObjectName(QStringLiteral("EachPath"));
        EachPath->resize(1366, 768);

        retranslateUi(EachPath);

        QMetaObject::connectSlotsByName(EachPath);
    } // setupUi

    void retranslateUi(QWidget *EachPath)
    {
        EachPath->setWindowTitle(QApplication::translate("EachPath", "EachPath", 0));
    } // retranslateUi

};

namespace Ui {
    class EachPath: public Ui_EachPath {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EACHPATH_H
