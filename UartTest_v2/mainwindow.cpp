#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Vérification que l'UART fonctionne
    if(serial->open(QIODevice::ReadOnly))
    {
        ui->labelData->setText("UART connecté");
    }
    else
    {
        ui->labelData->setText("Erreur Uart");
    }

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

}

bool MainWindow::openSerial()
{
    if(serial->open(QIODevice::ReadOnly))
    {
        ui->labelData->setText("UART connecté");
        return true;
    }
    else
    {
        ui->lavbelData->setText(serial->errorString());
        return false;
    }
}

void MainWindow::setupSerial()
{
    if(openSerial())
    {
        connect(serial, &QSerialPort::readyRead, this, &MainWindow::readSerialData);
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
            updateUiValues(p, b)
        }
    }

}

Qlist<QbyteArray> MainWindow::extractFrames()
{

}
