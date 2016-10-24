/********************************************************************************
** Form generated from reading UI file 'acosetting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACOSETTING_H
#define UI_ACOSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ACOSetting
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *alpha_text;
    QLabel *label_2;
    QLineEdit *beta_text;
    QLineEdit *times_text;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *rou_text;
    QLabel *label_7;
    QLineEdit *pheromone_text;
    QLineEdit *ant_text;
    QLabel *label_8;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *ACOSetting)
    {
        if (ACOSetting->objectName().isEmpty())
            ACOSetting->setObjectName(QStringLiteral("ACOSetting"));
        ACOSetting->resize(604, 306);
        groupBox = new QGroupBox(ACOSetting);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 581, 211));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 100, 61, 20));
        alpha_text = new QLineEdit(groupBox);
        alpha_text->setObjectName(QStringLiteral("alpha_text"));
        alpha_text->setGeometry(QRect(130, 100, 113, 21));
        alpha_text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(380, 100, 61, 16));
        beta_text = new QLineEdit(groupBox);
        beta_text->setObjectName(QStringLiteral("beta_text"));
        beta_text->setGeometry(QRect(440, 100, 113, 21));
        times_text = new QLineEdit(groupBox);
        times_text->setObjectName(QStringLiteral("times_text"));
        times_text->setGeometry(QRect(440, 40, 113, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(340, 40, 91, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 160, 51, 20));
        rou_text = new QLineEdit(groupBox);
        rou_text->setObjectName(QStringLiteral("rou_text"));
        rou_text->setGeometry(QRect(130, 160, 113, 21));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(340, 160, 81, 20));
        pheromone_text = new QLineEdit(groupBox);
        pheromone_text->setObjectName(QStringLiteral("pheromone_text"));
        pheromone_text->setGeometry(QRect(440, 160, 113, 21));
        ant_text = new QLineEdit(groupBox);
        ant_text->setObjectName(QStringLiteral("ant_text"));
        ant_text->setGeometry(QRect(130, 40, 113, 21));
        ant_text->setLayoutDirection(Qt::LeftToRight);
        ant_text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 40, 91, 20));
        okButton = new QPushButton(ACOSetting);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(370, 260, 93, 28));
        cancelButton = new QPushButton(ACOSetting);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(500, 260, 93, 28));

        retranslateUi(ACOSetting);

        QMetaObject::connectSlotsByName(ACOSetting);
    } // setupUi

    void retranslateUi(QWidget *ACOSetting)
    {
        ACOSetting->setWindowTitle(QApplication::translate("ACOSetting", "ACOSetting", 0));
        groupBox->setTitle(QApplication::translate("ACOSetting", "ACO Parameter Setting", 0));
        label->setText(QApplication::translate("ACOSetting", "alpha:", 0));
        alpha_text->setText(QApplication::translate("ACOSetting", "1", 0));
        label_2->setText(QApplication::translate("ACOSetting", "beta:", 0));
        beta_text->setText(QApplication::translate("ACOSetting", "2", 0));
        times_text->setText(QApplication::translate("ACOSetting", "1000", 0));
        label_4->setText(QApplication::translate("ACOSetting", "max times:", 0));
        label_5->setText(QApplication::translate("ACOSetting", "  rou:", 0));
        rou_text->setText(QApplication::translate("ACOSetting", "0.8", 0));
        label_7->setText(QApplication::translate("ACOSetting", "pheromone:", 0));
        pheromone_text->setText(QApplication::translate("ACOSetting", "1", 0));
        ant_text->setText(QApplication::translate("ACOSetting", "20", 0));
        label_8->setText(QApplication::translate("ACOSetting", "ant count:", 0));
        okButton->setText(QApplication::translate("ACOSetting", "OK", 0));
        cancelButton->setText(QApplication::translate("ACOSetting", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class ACOSetting: public Ui_ACOSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACOSETTING_H
