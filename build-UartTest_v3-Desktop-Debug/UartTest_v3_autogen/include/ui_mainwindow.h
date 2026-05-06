/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "jaugeeclair.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAjuster_Luminosit;
    QAction *actionSwitch_Reseaux;
    QAction *actionStatistiques;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *pourcent;
    QLCDNumber *lcdBattery;
    QLabel *W;
    QLCDNumber *lcdTemp;
    QWidget *widget_2;
    QLCDNumber *lcdPower;
    QLabel *labelBattery;
    QLabel *celcius;
    QLabel *labelTemp;
    QLabel *labelPower;
    JaugeEclair *PowerJauge;
    QLabel *labelData;
    QWidget *widget;
    QMenuBar *menubar;
    QMenu *menuOptions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(828, 421);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0)"));
        actionAjuster_Luminosit = new QAction(MainWindow);
        actionAjuster_Luminosit->setObjectName("actionAjuster_Luminosit");
        actionSwitch_Reseaux = new QAction(MainWindow);
        actionSwitch_Reseaux->setObjectName("actionSwitch_Reseaux");
        actionStatistiques = new QAction(MainWindow);
        actionStatistiques->setObjectName("actionStatistiques");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        pourcent = new QLabel(centralwidget);
        pourcent->setObjectName("pourcent");
        pourcent->setStyleSheet(QString::fromUtf8("font: 600 60pt \"URW Gothic [urw]\";\n"
"color: rgb(255,255,255)"));
        pourcent->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout->addWidget(pourcent, 9, 2, 1, 1);

        lcdBattery = new QLCDNumber(centralwidget);
        lcdBattery->setObjectName("lcdBattery");
        lcdBattery->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255)"));

        gridLayout->addWidget(lcdBattery, 9, 1, 1, 1);

        W = new QLabel(centralwidget);
        W->setObjectName("W");
        W->setAutoFillBackground(false);
        W->setStyleSheet(QString::fromUtf8("font: 600 50pt \"URW Gothic [urw]\";\n"
"color: rgb(255,255,255)"));
        W->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout->addWidget(W, 6, 2, 1, 1);

        lcdTemp = new QLCDNumber(centralwidget);
        lcdTemp->setObjectName("lcdTemp");
        lcdTemp->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255)\n"
""));

        gridLayout->addWidget(lcdTemp, 6, 4, 1, 1);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");

        gridLayout->addWidget(widget_2, 9, 4, 1, 2);

        lcdPower = new QLCDNumber(centralwidget);
        lcdPower->setObjectName("lcdPower");
        lcdPower->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255)"));

        gridLayout->addWidget(lcdPower, 6, 1, 1, 1);

        labelBattery = new QLabel(centralwidget);
        labelBattery->setObjectName("labelBattery");
        labelBattery->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)"));

        gridLayout->addWidget(labelBattery, 8, 1, 1, 1);

        celcius = new QLabel(centralwidget);
        celcius->setObjectName("celcius");
        QFont font;
        font.setFamilies({QString::fromUtf8("URW Gothic [urw]")});
        font.setPointSize(60);
        font.setBold(true);
        celcius->setFont(font);
        celcius->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)\n"
""));
        celcius->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout->addWidget(celcius, 6, 5, 1, 1);

        labelTemp = new QLabel(centralwidget);
        labelTemp->setObjectName("labelTemp");
        labelTemp->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)"));

        gridLayout->addWidget(labelTemp, 4, 4, 1, 1);

        labelPower = new QLabel(centralwidget);
        labelPower->setObjectName("labelPower");
        labelPower->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)"));

        gridLayout->addWidget(labelPower, 4, 1, 1, 1);

        PowerJauge = new JaugeEclair(centralwidget);
        PowerJauge->setObjectName("PowerJauge");
        PowerJauge->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(PowerJauge, 6, 3, 1, 1);

        labelData = new QLabel(centralwidget);
        labelData->setObjectName("labelData");
        labelData->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)"));

        gridLayout->addWidget(labelData, 0, 1, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");

        gridLayout->addWidget(widget, 9, 3, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 828, 19));
        menubar->setStyleSheet(QString::fromUtf8("color: rgb(255,255,255)"));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName("menuOptions");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionAjuster_Luminosit);
        menuOptions->addAction(actionSwitch_Reseaux);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAjuster_Luminosit->setText(QCoreApplication::translate("MainWindow", "Ajuster Luminosit\303\251", nullptr));
        actionSwitch_Reseaux->setText(QCoreApplication::translate("MainWindow", "Switch Reseaux", nullptr));
        actionStatistiques->setText(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        pourcent->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        W->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        labelBattery->setText(QCoreApplication::translate("MainWindow", "Batterie : -- %", nullptr));
        celcius->setText(QCoreApplication::translate("MainWindow", "\302\260C", nullptr));
        labelTemp->setText(QCoreApplication::translate("MainWindow", "Temperature : -- \302\260C", nullptr));
        labelPower->setText(QCoreApplication::translate("MainWindow", "Puissance : -- W", nullptr));
        labelData->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
