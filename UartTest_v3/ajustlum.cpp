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

    connect(ui->horizontalSlider,&QSlider::sliderReleased,this,&Ajustlum::displayLum);

}

Ajustlum::~Ajustlum()
{
    delete ui;
}

void Ajustlum::displayLum()
{
    ui->lcdNumber->display(ui->horizontalSlider->value());
    stateSlider = QString::number(ui->horizontalSlider->value()) + "\r";
    emit activateSerialWrite_Slider();
}

QString Ajustlum::get_sliderState()
{
    return stateSlider;
}
