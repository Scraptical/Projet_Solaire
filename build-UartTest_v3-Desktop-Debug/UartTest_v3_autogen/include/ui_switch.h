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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Switch
{
public:
    QGridLayout *gridLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label_3;

    void setupUi(QDialog *Switch)
    {
        if (Switch->objectName().isEmpty())
            Switch->setObjectName("Switch");
        Switch->resize(400, 304);
        gridLayout = new QGridLayout(Switch);
        gridLayout->setObjectName("gridLayout");
        checkBox = new QCheckBox(Switch);
        checkBox->setObjectName("checkBox");

        gridLayout->addWidget(checkBox, 1, 0, 1, 1);

        checkBox_2 = new QCheckBox(Switch);
        checkBox_2->setObjectName("checkBox_2");

        gridLayout->addWidget(checkBox_2, 1, 1, 1, 1);

        label_3 = new QLabel(Switch);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 0, 1, 2);


        retranslateUi(Switch);

        QMetaObject::connectSlotsByName(Switch);
    } // setupUi

    void retranslateUi(QDialog *Switch)
    {
        Switch->setWindowTitle(QCoreApplication::translate("Switch", "Dialog", nullptr));
        checkBox->setText(QCoreApplication::translate("Switch", "Reseau EDF", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Switch", "Batterie", nullptr));
        label_3->setText(QCoreApplication::translate("Switch", "Configuration Actuelle : ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Switch: public Ui_Switch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWITCH_H
