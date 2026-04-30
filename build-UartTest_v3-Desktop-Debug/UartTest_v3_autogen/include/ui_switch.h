/********************************************************************************
** Form generated from reading UI file 'switch.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWITCH_H
#define UI_SWITCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Switch
{
public:
    QGridLayout *gridLayout;
    QRadioButton *RadioBat;
    QRadioButton *RadioRes;
    QLabel *label_3;

    void setupUi(QDialog *Switch)
    {
        if (Switch->objectName().isEmpty())
            Switch->setObjectName("Switch");
        Switch->resize(400, 100);
        Switch->setStyleSheet(QString::fromUtf8("background-color: rgb(0,0,0);\n"
"border-color: rgb(0, 0, 0);\n"
""));
        gridLayout = new QGridLayout(Switch);
        gridLayout->setObjectName("gridLayout");
        RadioBat = new QRadioButton(Switch);
        RadioBat->setObjectName("RadioBat");
        RadioBat->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(RadioBat, 1, 1, 1, 1);

        RadioRes = new QRadioButton(Switch);
        RadioRes->setObjectName("RadioRes");
        RadioRes->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(RadioRes, 1, 0, 1, 1);

        label_3 = new QLabel(Switch);
        label_3->setObjectName("label_3");
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(255, 255, 255, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        label_3->setPalette(palette);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255);\n"
"font: 20pt \"Sans Serif\";"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 0, 1, 2);


        retranslateUi(Switch);

        QMetaObject::connectSlotsByName(Switch);
    } // setupUi

    void retranslateUi(QDialog *Switch)
    {
        Switch->setWindowTitle(QCoreApplication::translate("Switch", "Dialog", nullptr));
        RadioBat->setText(QCoreApplication::translate("Switch", "Batterie", nullptr));
        RadioRes->setText(QCoreApplication::translate("Switch", "Reseau EDF", nullptr));
        label_3->setText(QCoreApplication::translate("Switch", "Configuration Actuelle : ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Switch: public Ui_Switch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWITCH_H
