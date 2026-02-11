#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupSerial();
    verifSerial();

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

void MainWindow::verifSerial()
{
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

void MainWindow::readSerialData()
{
    serialBuffer += serial->readAll();
    qDebug() << serialBuffer;

    while(serialBuffer.contains('\r'))
    {
        stockage = QString(serialBuffer);
        int index = serialBuffer.indexOf('\r');
        QByteArray ligne = serialBuffer.left(index);
        serialBuffer.remove(0, index + 1);

        ui->labelData->setText(QString::fromUtf8(ligne));

        trameISjson(ligne);
        makeFile();
    }
}

QJsonDocument MainWindow::trameISjson(const QByteArray &data)
{
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(data, &err);
    qDebug() << "avant if : " << doc;
        if (err.error != QJsonParseError::NoError || !doc.isObject())
        {
            qDebug() << "JSON invalide : " << data;
            return doc;
        }

        convertData(doc);
        return doc;
}

QPair<double, int> MainWindow::convertData(QJsonDocument doc)
{
    QJsonObject obj = doc.object();
    if(obj.contains("P") && obj.contains("B"))      //On peut altérer cette ligne pour reconnaitre plusieurs lettres comme la tension (T) ou l'intensité (I)
    {
        double puissance = obj["P"].toDouble();     //Même chose, on peut rajouter des lignes pour les nouvelle lettres en suivant la même logique
        int batterie = obj["B"].toInt();

        QPair<double, int> valeur(puissance, batterie);

        updateUIvalue(valeur);
        return valeur;

    }
}

void MainWindow::updateUIvalue(QPair<double, int> valeur)
{
    qDebug() << "Mise à jour UI, veuillez patienter...";
    ui->labelPower->setText(QString("Puissance : %1 W").arg(valeur.first));    //Ne pas oublier de rajouter des label dans la UI lorsqu'on rajoute des valeurs !!
    ui->labelBattery->setText(QString("Batterie : %1 %").arg(valeur.second));
}

void MainWindow::makeFile()
{
    QFile File("data.json");
    if (File.open(QIODevice::Truncate | QIODevice::ReadWrite))
    {
        QTextStream stream(&File);
        qDebug() << "test n°x : " << stockage;
        stream << QString(stockage);
        qDebug() << "Fichier créé avec succès !";
        qDebug() << "Chemin : " << QFileInfo(File).absoluteFilePath();
    }
    File.close();
}
