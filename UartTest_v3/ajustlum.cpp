#include "ajustlum.h"
#include "ui_ajustlum.h"

Ajustlum::Ajustlum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajustlum)
{
    ui->setupUi(this);

    ui->horizontalSlider->setStyleSheet("background-color: rgb(255,255,255)");
    ui->horizontalSlider->setValue(50);
    ui->lcdNumber->display(50);

    connect(ui->horizontalSlider,SIGNAL(sliderMoved(int)),ui->lcdNumber,SLOT(display(int)));
}

Ajustlum::~Ajustlum()
{
    delete ui;
}


