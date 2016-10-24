/********************************************************************************
** Form generated from reading UI file 'aialogrithm.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIALOGRITHM_H
#define UI_AIALOGRITHM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AIAlogrithmClass
{
public:
    QAction *actionAS;
    QAction *actionAnt_Colony_Optimization;
    QAction *actionCity_Positions_Setting;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuTSP;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AIAlogrithmClass)
    {
        if (AIAlogrithmClass->objectName().isEmpty())
            AIAlogrithmClass->setObjectName(QStringLiteral("AIAlogrithmClass"));
        AIAlogrithmClass->setWindowModality(Qt::ApplicationModal);
        AIAlogrithmClass->resize(1291, 757);
        QIcon icon;
        icon.addFile(QStringLiteral("YTs.ico"), QSize(), QIcon::Normal, QIcon::Off);
        AIAlogrithmClass->setWindowIcon(icon);
        actionAS = new QAction(AIAlogrithmClass);
        actionAS->setObjectName(QStringLiteral("actionAS"));
        actionAnt_Colony_Optimization = new QAction(AIAlogrithmClass);
        actionAnt_Colony_Optimization->setObjectName(QStringLiteral("actionAnt_Colony_Optimization"));
        actionAnt_Colony_Optimization->setEnabled(false);
        actionCity_Positions_Setting = new QAction(AIAlogrithmClass);
        actionCity_Positions_Setting->setObjectName(QStringLiteral("actionCity_Positions_Setting"));
        centralWidget = new QWidget(AIAlogrithmClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        AIAlogrithmClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AIAlogrithmClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1291, 26));
        menuTSP = new QMenu(menuBar);
        menuTSP->setObjectName(QStringLiteral("menuTSP"));
        AIAlogrithmClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(AIAlogrithmClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AIAlogrithmClass->setStatusBar(statusBar);

        menuBar->addAction(menuTSP->menuAction());
        menuTSP->addSeparator();
        menuTSP->addAction(actionCity_Positions_Setting);
        menuTSP->addAction(actionAnt_Colony_Optimization);

        retranslateUi(AIAlogrithmClass);

        QMetaObject::connectSlotsByName(AIAlogrithmClass);
    } // setupUi

    void retranslateUi(QMainWindow *AIAlogrithmClass)
    {
        AIAlogrithmClass->setWindowTitle(QApplication::translate("AIAlogrithmClass", "AIAlogrithm", 0));
        actionAS->setText(QApplication::translate("AIAlogrithmClass", "AS", 0));
        actionAnt_Colony_Optimization->setText(QApplication::translate("AIAlogrithmClass", "Ant Colony Optimization", 0));
        actionCity_Positions_Setting->setText(QApplication::translate("AIAlogrithmClass", "City Positions Setting", 0));
        menuTSP->setTitle(QApplication::translate("AIAlogrithmClass", "TSP", 0));
    } // retranslateUi

};

namespace Ui {
    class AIAlogrithmClass: public Ui_AIAlogrithmClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIALOGRITHM_H
