#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupSerial();

    connect(serial, &QSerialPort::readyRead,this, &MainWindow::readSerialData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupSerial()
{
    serial = new QSerialPort(this);

    //Mise en place des Bauds, bits, bit de parité et bit de stop
    serial->setPortName("/dev/serial0");
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    openSerial();

}

bool MainWindow::openSerial()
{
    if(serial->open(QIODevice::ReadOnly))
    {
        ui->labelData->setText("UART connecté");
        return true;
        readSerialData();
    }
    else
    {
        ui->labelData->setText(serial->errorString());
        return false;
    }
}

//Lecture de la trame via Terra Term
//Il faut appuyer sur "entrer" pour faire s'afficher le message
void MainWindow::readSerialData()
{
    QByteArray data = serial->readAll();
    traiterTrame(data);
}

//Decriptage d'un mesage en JSON uniquement pour le placer dans les Label associé
//Première partie pour savoir si la trame est en format JSON (si c pas le cas, alors il affiche une erreur)
void MainWindow::traiterTrame(const QByteArray& data)
{
    serial += data;
    auto frames = extractFrames();
    for (const QByteArray& frame : frames)
    {
        stockage = QString::fromUtf8(frame);

        ui->labelData->setText(stockage);
        saveToJsonFile(stockage);

        double p;
        int b;

        if (parseJsonFrame(frame, p, b))
        {
            updateUiValues(p, b);
        }
    }

}

QList<QByteArray> MainWindow::extractFrames()
{
    QList<QByteArray> frames;
    while(serialBuffer.contains('\r'))
    {
        int index = serialBuffer.indexOf('\r');
        frames.append(serialBuffer.left(index));
        serialBuffer.remove(1, index+1);
    }
    return frames;
}

bool MainWindow::parseJsonFrame(const QByteArray& frame, double &p, int &b)
{
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(frame, &err);

    if (err.error != QJsonParseError::NoError || !doc.isObject())
    {
        return false;
    }

    QJsonObject obj = doc.object();

    if(!obj.contains("P") || !obj.contains("B"))
    {
        return false;
    }

    p = obj["P"].toDouble();
    b = obj["B"].toInt();

    return true;
}

void MainWindow::updateUiValues(double puissance, int batterie)
{
    ui->labelPower->setText(QString("Puissance : %1 W").arg(puissance));
    ui->labelBattery->setText(QString("Batterie : %1 %").arg(batterie));
}

void MainWindow::saveToJsonFile(const QString& text)
{
    QFile file("data.json");

    if(file.open(QIODevice::Truncate | QIODevice::WriteOnly))
    {
        QTextStream stream(&file);
        stream << text;
        file.close();
    }
}
