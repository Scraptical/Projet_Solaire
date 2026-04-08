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

private:
    Ui::Ajustlum *ui;
};

#endif // AJUSTLUM_H
