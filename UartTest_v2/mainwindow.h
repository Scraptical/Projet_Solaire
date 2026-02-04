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

    void setupSerial();
    bool openSerial();
    void traiterTrame(const QByteArray& data);
    QList<QByteArray> extractFrames();
    bool parseJsonFrame(const QByteArray& frame, double &p, int &b);
    void updateUiValues(double puissance, int batterie);
    void saveToJsonFile(const QString& text);

private slots:
    void readSerialData();

};
#endif // MAINWINDOW_H
