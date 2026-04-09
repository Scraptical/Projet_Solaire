#include "switch.h"
#include "ui_switch.h"

Switch::Switch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Switch)
{
    ui->setupUi(this);

    ui->checkBox->setStyleSheet("background-color: rgb(255,255,255)");
    ui->checkBox_2->setStyleSheet("background-color: rgb(255,255,255)");

    connect(ui->checkBox,&QCheckBox::clicked,ui->checkBox_2,&QCheckBox::setDisabled);
    connect(ui->checkBox_2,&QCheckBox::clicked,ui->checkBox,&QCheckBox::setDisabled);
}

Switch::~Switch()
{
    delete ui;
}
