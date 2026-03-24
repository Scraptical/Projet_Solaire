#include <QtTest/QtTest>
#include "mainwindow.h"
class UARTUnitaire : public QObject
{
    Q_OBJECT

private slots :
    void test_VerifSerial()
    {
        QVERIFY(MainWindow::verifSerial());
    }

    void test_trameISjson()
    {

    }
};
QTEST_MAIN(UARTUnitaire)
#include "UartUnitaire.moc"
