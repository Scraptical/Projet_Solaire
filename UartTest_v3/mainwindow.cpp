#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "jaugeeclair.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), ajustlum(new Ajustlum)
{
    ui->setupUi(this);

    //On commence le programme avec ces 2 méthode,
    //une pour mettre en place les information de communications,
    //et l'autre pour lancer la lecture de la tramme (et tous le programme)
    setupSerial();
    verifSerial();

    connect(ui->actionAjuster_Luminosit,&QAction::triggered,this,&MainWindow::open_slider);

    gauge = new JaugeEclair(this);
    gauge->setGeometry(50, 50, 150, 200);

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
        ui->labelData->setText("UART connecté"); //Connexion réussit
    }
    else
    {
        ui->labelData->setText("Erreur Uart"); //Connexion échoué
    }

    connect(serial, &QSerialPort::readyRead,this, &MainWindow::readSerialData); //Dans tous les cas, on continue
}

void MainWindow::readSerialData()
{
    serialBuffer += serial->readAll();
    qDebug() << serialBuffer; //indique ce que l'on tape dans la console (au cas où on fait n'importe quoi)

    while(serialBuffer.contains('\r')) //Quand on appuis sur 'entrée'
    {
        stockage = QString(serialBuffer); //Stockage qui sera placé sur le fichier.json
        int index = serialBuffer.indexOf('\r'); //on retient l'emplacement de la touche 'entrée'
        QByteArray ligne = serialBuffer.left(index);
        serialBuffer.remove(0, index + 1);

        ui->labelData->setText("Trame reçu : " + QString::fromUtf8(ligne)); //la ligne reçu est marqué sur l'interface

        trameISjson(ligne);
        makeFile();
    }

}

QJsonDocument MainWindow::trameISjson(const QByteArray &data)
{
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(data, &err);
        if (err.error != QJsonParseError::NoError || !doc.isObject()) //On check si la ligne reçu correspond bien au format JSON
        {
            qDebug() << "JSON invalide : " << data; //C'est pas le cas ? On le note dans la console
            return doc;
        }

        convertData(doc); // Le format est valide ? Alors on passe à la suite
        return doc;
}

Valeurs MainWindow::convertData(QJsonDocument doc)
{
    Valeurs valeurs;
    QJsonObject obj = doc.object(); //on transforme note ligne en obj
    if(obj.contains("P") && obj.contains("B") && obj.contains("T")) //On peut altérer cette ligne pour reconnaitre plusieurs lettres comme la tension (T) ou l'intensité (I)
    {
        valeurs.puissance = obj["P"].toDouble(); //Même chose, on peut rajouter des lignes pour les nouvelle lettres en suivant la même logique
        valeurs.batterie = obj["B"].toInt();
        valeurs.temp = obj["T"].toInt();

        updateUIvalue(valeurs);
        return valeurs;

    }
}

void MainWindow::updateUIvalue(Valeurs valeurs)
{
    qDebug() << "Mise à jour UI, veuillez patienter..."; //ça sert a rien, mais ça semble plus professionnel :/
    ui->labelPower->setText(QString("Puissance : %1 W").arg(valeurs.puissance)); //On met les valeur extracté de la trame dans l'IHM
    ui->lcdPower->display(valeurs.puissance);
    gauge->setValue(70);
    ui->PowerJauge->setValue(75);
    ui->labelBattery->setText(QString("Batterie : %1 %").arg(valeurs.batterie));
    ui->lcdBattery->display(valeurs.batterie);
    ui->labelTemp->setText(QString("Temperature : %1 °C").arg(valeurs.temp));
    ui->lcdTemp->display(valeurs.temp);
    //Ne pas oublier de rajouter des label dans la UI lorsqu'on rajoute des valeurs !!
}

void MainWindow::makeFile()
{
    QFile File("data.json");
    if (File.open(QIODevice::Truncate | QIODevice::ReadWrite)) //Obligatoire pour écrire dans le fichier
    {
        QTextStream stream(&File);
        qDebug() << "test n°x : " << stockage; //On check dans la console si ce qui est écris dans le fichier est correct !
        stream << QString(stockage); //La tramme est écris dans le fichier .JSON
        qDebug() << "Fichier créé avec succès !"; //On confirme la réussite :D
        qDebug() << "Chemin : " << QFileInfo(File).absoluteFilePath(); //On vérifie où le dossier est enregistrer au cas où on le perd
        //Beaucoup trop de debug ici...
    }
    File.close();
}

void MainWindow::open_slider()
{
    ajustlum->open();
}
