#include "switch.h"
#include "ui_switch.h"

Switch::Switch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Switch)
{
    ui->setupUi(this);

    ui->RadioRes->setStyleSheet("background-color: rgb(255,255,255)");
    ui->RadioBat->setStyleSheet("background-color: rgb(255,255,255)");
    ui->RadioRes->setChecked(1);
    ui->RadioBat->setChecked(0);
    stateSwitch = "EDF\n";

    connect(ui->RadioRes,&QRadioButton::clicked,this,&Switch::UncheckBat);
    connect(ui->RadioBat,&QRadioButton::clicked,this,&Switch::UncheckRes);
}

Switch::~Switch()
{
    delete ui;
}

void Switch::UncheckBat()
{
    qDebug() << "Mode Reseau EDF";
    stateSwitch = "EDF\r";
    emit activateSerialWrite_Switch();
}

void Switch::UncheckRes()
{
    qDebug() << "Mode Batterie";
    stateSwitch = "BAT\r";
    emit activateSerialWrite_Switch();
}

QString Switch::get_switchState()
{
    return stateSwitch;
}
