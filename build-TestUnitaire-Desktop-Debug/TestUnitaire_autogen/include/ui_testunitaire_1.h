/********************************************************************************
** Form generated from reading UI file 'testunitaire_1.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTUNITAIRE_1_H
#define UI_TESTUNITAIRE_1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestUnitaire_1
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestUnitaire_1)
    {
        if (TestUnitaire_1->objectName().isEmpty())
            TestUnitaire_1->setObjectName("TestUnitaire_1");
        TestUnitaire_1->resize(800, 600);
        centralwidget = new QWidget(TestUnitaire_1);
        centralwidget->setObjectName("centralwidget");
        TestUnitaire_1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestUnitaire_1);
        menubar->setObjectName("menubar");
        TestUnitaire_1->setMenuBar(menubar);
        statusbar = new QStatusBar(TestUnitaire_1);
        statusbar->setObjectName("statusbar");
        TestUnitaire_1->setStatusBar(statusbar);

        retranslateUi(TestUnitaire_1);

        QMetaObject::connectSlotsByName(TestUnitaire_1);
    } // setupUi

    void retranslateUi(QMainWindow *TestUnitaire_1)
    {
        TestUnitaire_1->setWindowTitle(QCoreApplication::translate("TestUnitaire_1", "TestUnitaire_1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestUnitaire_1: public Ui_TestUnitaire_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTUNITAIRE_1_H
