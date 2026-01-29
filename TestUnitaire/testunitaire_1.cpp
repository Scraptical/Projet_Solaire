#include "../UartTest/mainwindow.h"
#include "./ui_testunitaire_1.h"
#include <QtTest/QtTest>

class TESTUART : public QObject
{
    Q_OBJECT

private slots :
    void testUart()
    {
        QCOMPARE(MainWindow::readSerialData(),);
    }
};
QTEST_MAIN(TESTUART)
#include "testunitaire_1.moc"

