/********************************************************************************
** Form generated from reading UI file 'ajustlum.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJUSTLUM_H
#define UI_AJUSTLUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Ajustlum
{
public:
    QGridLayout *gridLayout;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QSlider *horizontalSlider;

    void setupUi(QDialog *Ajustlum)
    {
        if (Ajustlum->objectName().isEmpty())
            Ajustlum->setObjectName("Ajustlum");
        Ajustlum->resize(400, 300);
        gridLayout = new QGridLayout(Ajustlum);
        gridLayout->setObjectName("gridLayout");
        lcdNumber = new QLCDNumber(Ajustlum);
        lcdNumber->setObjectName("lcdNumber");

        gridLayout->addWidget(lcdNumber, 3, 0, 1, 1);

        label = new QLabel(Ajustlum);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSlider = new QSlider(Ajustlum);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 1, 0, 1, 1);


        retranslateUi(Ajustlum);

        QMetaObject::connectSlotsByName(Ajustlum);
    } // setupUi

    void retranslateUi(QDialog *Ajustlum)
    {
        Ajustlum->setWindowTitle(QCoreApplication::translate("Ajustlum", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Ajustlum", "Ajustez la luminosit\303\251 :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ajustlum: public Ui_Ajustlum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJUSTLUM_H
