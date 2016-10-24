/********************************************************************************
** Form generated from reading UI file 'citysetting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CITYSETTING_H
#define UI_CITYSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CitySetting
{
public:
    QGroupBox *groupBox;
    QComboBox *data_source;
    QLabel *label_6;
    QLineEdit *city_text;
    QLabel *label_3;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *CitySetting)
    {
        if (CitySetting->objectName().isEmpty())
            CitySetting->setObjectName(QStringLiteral("CitySetting"));
        CitySetting->resize(366, 236);
        groupBox = new QGroupBox(CitySetting);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 331, 161));
        data_source = new QComboBox(groupBox);
        data_source->setObjectName(QStringLiteral("data_source"));
        data_source->setGeometry(QRect(140, 30, 111, 22));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 30, 101, 20));
        city_text = new QLineEdit(groupBox);
        city_text->setObjectName(QStringLiteral("city_text"));
        city_text->setGeometry(QRect(140, 100, 113, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 100, 91, 20));
        cancelButton = new QPushButton(CitySetting);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(290, 190, 61, 28));
        okButton = new QPushButton(CitySetting);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(192, 190, 71, 28));

        retranslateUi(CitySetting);

        data_source->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CitySetting);
    } // setupUi

    void retranslateUi(QDialog *CitySetting)
    {
        CitySetting->setWindowTitle(QApplication::translate("CitySetting", "CitySetting", 0));
        groupBox->setTitle(QApplication::translate("CitySetting", "CitySetting", 0));
        data_source->clear();
        data_source->insertItems(0, QStringList()
         << QApplication::translate("CitySetting", "Random", 0)
         << QApplication::translate("CitySetting", "FromFile", 0)
        );
        label_6->setText(QApplication::translate("CitySetting", " data source:", 0));
        city_text->setText(QApplication::translate("CitySetting", "50", 0));
        label_3->setText(QApplication::translate("CitySetting", "city count:", 0));
        cancelButton->setText(QApplication::translate("CitySetting", "Cancel", 0));
        okButton->setText(QApplication::translate("CitySetting", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class CitySetting: public Ui_CitySetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CITYSETTING_H
