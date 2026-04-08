#include "ajustlum.h"
#include "ui_ajustlum.h"

Ajustlum::Ajustlum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajustlum)
{
    ui->setupUi(this);

    connect(ui->horizontalSlider,SIGNAL(sliderMoved(int)),ui->lcdNumber,SLOT(display(int)));
}

Ajustlum::~Ajustlum()
{
    delete ui;
}


