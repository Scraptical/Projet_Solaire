#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "options.h"

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

struct Valeurs
{
    double puissance = 0;
    int batterie = 0;
    int temp = 0;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setupSerial();
    void verifSerial();
    void readSerialData();
    QJsonDocument trameISjson(const QByteArray& data);
    Valeurs convertData(QJsonDocument doc);
    void updateUIvalue(Valeurs);
    void makeFile();

    void open_slider();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QByteArray serialBuffer;
    QString stockage;
    Options *options;

private slots:

};
#endif // MAINWINDOW_H
