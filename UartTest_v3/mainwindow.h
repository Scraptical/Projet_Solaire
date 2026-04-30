#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ajustlum.h"
#include "switch.h"

#include "jaugeeclair.h"

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
#include <QPainter>
#include <QTime>
#include <QTimer>

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
    void open_reseaux();
    QString getState();
    void SendTrame_etat();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QByteArray serialBuffer;
    QString stockage;

    Ajustlum *ajustlum;
    Switch *switche;

    JaugeEclair *gauge;

    QString etat;
    QTimer *timer;

private slots:

};
#endif // MAINWINDOW_H
