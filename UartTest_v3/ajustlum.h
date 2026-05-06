#ifndef AJUSTLUM_H
#define AJUSTLUM_H

#include <QDialog>
#include <QLCDNumber>

namespace Ui {
class Ajustlum;
}

class Ajustlum : public QDialog
{
    Q_OBJECT

public:
    explicit Ajustlum(QWidget *parent = nullptr);
    ~Ajustlum();
    void displayLum();
    QString get_sliderState();

private:
    Ui::Ajustlum *ui;
    QString stateSlider;
    int valueSlider;

signals:
    void activateSerialWrite_Slider();
};

#endif // AJUSTLUM_H
