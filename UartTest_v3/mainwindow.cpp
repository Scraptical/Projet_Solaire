#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "jaugeeclair.h"
#include "jaugebatterie.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), ajustlum(new Ajustlum), switche(new Switch)
{
    ui->setupUi(this);

    setupSerial();
    verifSerial();

    connect(ui->actionAjuster_Luminosit,&QAction::triggered,this,&MainWindow::open_slider);
    connect(ui->actionSwitch_Reseaux,&QAction::triggered,this,&MainWindow::open_reseaux);

    ui->PowerJauge->setValue(0);
    ui->BatteryJauge->setValue(0);

    connect(switche,&Switch::activateSerialWrite_Switch,this,&MainWindow::SendTrame_etatSwitch);
    connect(ajustlum,&Ajustlum::activateSerialWrite_Slider,this,&MainWindow::SendTrame_etatSlider);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupSerial()
{
    serial = new QSerialPort(this);

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
    if(serial->open(QIODevice::ReadWrite))
    {
        ui->labelData->setText("UART connecté"); //Connexion réussit
    }
    else
    {
        ui->labelData->setText("Erreur Uart"); //Connexion échoué
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

        ui->labelData->setText("Trame reçu : " + QString::fromUtf8(ligne));

        trameISjson(ligne);
        makeFile();
    }

}

QJsonDocument MainWindow::trameISjson(const QByteArray &data)
{
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(data, &err);
        if (err.error != QJsonParseError::NoError || !doc.isObject())
        {
            qDebug() << "JSON invalide : " << data;
            return doc;
        }

        convertData(doc);
        return doc;
}

Valeurs MainWindow::convertData(QJsonDocument doc)
{
    Valeurs valeurs;
    QJsonObject obj = doc.object();
    if(obj.contains("P") && obj.contains("B") && obj.contains("T"))
    {
        valeurs.puissance = obj["P"].toDouble();
        valeurs.batterie = obj["B"].toInt();
        valeurs.temp = obj["T"].toInt();

        updateUIvalue(valeurs);
        return valeurs;

    }
}

void MainWindow::updateUIvalue(Valeurs valeurs)
{
    qDebug() << "Mise à jour UI, veuillez patienter...";
    ui->labelPower->setText(QString("Puissance : %1 W").arg(valeurs.puissance));
    ui->lcdPower->display(valeurs.puissance);
    ui->PowerJauge->setValue(int(valeurs.puissance));
    ui->labelBattery->setText(QString("Batterie : %1 %").arg(valeurs.batterie));
    ui->lcdBattery->display(valeurs.batterie);
    ui->BatteryJauge->setValue(int(valeurs.batterie));
    ui->labelTemp->setText(QString("Temperature : %1 °C").arg(valeurs.temp));
    ui->lcdTemp->display(valeurs.temp);
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

void MainWindow::open_slider()
{
    ajustlum->open();
}

void MainWindow::open_reseaux()
{
    switche->open();
}

void MainWindow::getState_switch()
{
    etatSwitch = switche->get_switchState();
    qDebug() << "etat : " << etatSwitch;
}

void MainWindow::SendTrame_etatSwitch()
{
    getState_switch();
    serial->write(etatSwitch.toUtf8());
    qDebug() << "transaction alimentation terminé";
}

void MainWindow::getState_slider()
{
    etatSlider = ajustlum->get_sliderState();
    qDebug() << "etat : " << etatSlider;
}

void MainWindow::SendTrame_etatSlider()
{
    getState_slider();
    serial->write(etatSlider.toUtf8());
    qDebug() << "transaction luminosité terminé";
}

