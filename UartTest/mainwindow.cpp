#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serial = new QSerialPort(this);

    //Mise en place des Bauds, bits, bit de parité et bit de stop
    serial->setPortName("/dev/serial0");
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

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

//Lecture de la trame via Terra Term
//Il faut appuyer sur "entrer" pour faire s'afficher le message
void MainWindow::readSerialData()
{
    // Cette partie en commentaire est a utiliser en cas de bug / problème

    /*QByteArray data = serial->readAll();
    qDebug() << "Reçu" << data;

    ui->labelData->setText(ui->labelData->text() + QString::fromUtf8(data)); */

    serialBuffer += serial->readAll();

    while(serialBuffer.contains('\r'))
    {
        int index = serialBuffer.indexOf('\r');
        QByteArray line = serialBuffer.left(index);
        serialBuffer.remove(0, index + 1);

        ui->labelData->setText(QString::fromUtf8(line));

        traiterTrame(line);
    }
}

//Decriptage d'un mesage en JSON uniquement pour le placer dans les Label associé
//Première partie pour savoir si la trame est en format JSON (si c pas le cas, alors il affiche une erreur)
void MainWindow::traiterTrame(const QByteArray& trame)
{
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(trame, &err);
        if (err.error != QJsonParseError::NoError || !doc.isObject())
        {
            qDebug() << "JSON invalide : " << trame;
            return;
        }

    QJsonObject obj = doc.object();

    if(obj.contains("P") && obj.contains("B"))      //On peut altérer cette ligne pour reconnaitre plusieurs lettres comme la tension (T) ou l'intensité (I)
    {
        double puissance = obj["P"].toDouble();     //Même chose, on peut rajouter des lignes pour les nouvelle lettres en suivant la même logique
        int batterie = obj["B"].toInt();

        ui->labelPower->setText(QString("Puissance : %1 W").arg(puissance));        //Ne pas oublier de rajouter des label dans la UI lorsqu'on rajoute des valeurs !!

        ui->labelBattery->setText(QString("Batterie : %1 %").arg(batterie));
    }

}
