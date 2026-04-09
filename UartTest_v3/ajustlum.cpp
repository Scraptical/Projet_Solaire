#include "ajustlum.h"
#include "ui_ajustlum.h"

Ajustlum::Ajustlum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajustlum)
{
    ui->setupUi(this);

    ui->horizontalSlider->setStyleSheet("background-color: rgb(255,255,255)");

    connect(ui->horizontalSlider,SIGNAL(sliderMoved(int)),ui->lcdNumber,SLOT(display(int)));
}

Ajustlum::~Ajustlum()
{
    delete ui;
}


