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

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAjuster_Luminosit;
    QAction *actionSwitch_R_seaux;
    QAction *actionStatistiques;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *labelTemp;
    QLabel *W;
    QLabel *celcius;
    QLabel *labelBattery;
    QLCDNumber *lcdBattery;
    QLCDNumber *lcdPower;
    QLabel *pourcent;
    QLabel *labelPower;
    QLabel *labelData;
    QLCDNumber *lcdTemp;
    QMenuBar *menubar;
    QMenu *menuOptions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(994, 421);
        actionAjuster_Luminosit = new QAction(MainWindow);
        actionAjuster_Luminosit->setObjectName("actionAjuster_Luminosit");
        actionSwitch_R_seaux = new QAction(MainWindow);
        actionSwitch_R_seaux->setObjectName("actionSwitch_R_seaux");
        actionStatistiques = new QAction(MainWindow);
        actionStatistiques->setObjectName("actionStatistiques");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        labelTemp = new QLabel(centralwidget);
        labelTemp->setObjectName("labelTemp");

        gridLayout->addWidget(labelTemp, 4, 2, 1, 1);

        W = new QLabel(centralwidget);
        W->setObjectName("W");
        W->setAutoFillBackground(false);
        W->setStyleSheet(QString::fromUtf8("font: 600 50pt \"URW Gothic [urw]\";"));
        W->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout->addWidget(W, 5, 1, 1, 1);

        celcius = new QLabel(centralwidget);
        celcius->setObjectName("celcius");
        QFont font;
        font.setFamilies({QString::fromUtf8("URW Gothic [urw]")});
        font.setPointSize(60);
        font.setBold(true);
        celcius->setFont(font);
        celcius->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout->addWidget(celcius, 5, 3, 1, 1);

        labelBattery = new QLabel(centralwidget);
        labelBattery->setObjectName("labelBattery");

        gridLayout->addWidget(labelBattery, 7, 0, 1, 1);

        lcdBattery = new QLCDNumber(centralwidget);
        lcdBattery->setObjectName("lcdBattery");

        gridLayout->addWidget(lcdBattery, 8, 0, 1, 1);

        lcdPower = new QLCDNumber(centralwidget);
        lcdPower->setObjectName("lcdPower");

        gridLayout->addWidget(lcdPower, 5, 0, 1, 1);

        pourcent = new QLabel(centralwidget);
        pourcent->setObjectName("pourcent");
        pourcent->setStyleSheet(QString::fromUtf8("font: 600 60pt \"URW Gothic [urw]\";"));
        pourcent->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout->addWidget(pourcent, 8, 1, 1, 1);

        labelPower = new QLabel(centralwidget);
        labelPower->setObjectName("labelPower");

        gridLayout->addWidget(labelPower, 4, 0, 1, 1);

        labelData = new QLabel(centralwidget);
        labelData->setObjectName("labelData");

        gridLayout->addWidget(labelData, 3, 0, 1, 1);

        lcdTemp = new QLCDNumber(centralwidget);
        lcdTemp->setObjectName("lcdTemp");

        gridLayout->addWidget(lcdTemp, 5, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 994, 19));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName("menuOptions");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionAjuster_Luminosit);
        menuOptions->addAction(actionSwitch_R_seaux);
        menuOptions->addAction(actionStatistiques);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAjuster_Luminosit->setText(QCoreApplication::translate("MainWindow", "Ajuster Luminosit\303\251", nullptr));
        actionSwitch_R_seaux->setText(QCoreApplication::translate("MainWindow", "Switch Reseaux", nullptr));
        actionStatistiques->setText(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        labelTemp->setText(QCoreApplication::translate("MainWindow", "Temperature : -- \302\260C", nullptr));
        W->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        celcius->setText(QCoreApplication::translate("MainWindow", "\302\260C", nullptr));
        labelBattery->setText(QCoreApplication::translate("MainWindow", "Batterie : -- %", nullptr));
        pourcent->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
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
