#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include <QPair>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QByteArray serialBuffer;
    QString stockage;
    //const QByteArray& data;

private slots:
    void setupSerial();
    void verifSerial();
    void readSerialData();
    QJsonDocument trameISjson(const QByteArray& data);
    QPair<double, int> convertData(QJsonDocument doc);
    void updateUIvalue(QPair<double, int> valeur);
    void makeFile();
};
#endif // MAINWINDOW_H
