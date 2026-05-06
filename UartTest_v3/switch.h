#ifndef SWITCH_H
#define SWITCH_H

#include <QDialog>

namespace Ui {
class Switch;
}

class Switch : public QDialog
{
    Q_OBJECT

public:
    explicit Switch(QWidget *parent = nullptr);
    ~Switch();
    void UncheckBat();
    void UncheckRes();
    QString get_switchState();

private:
    Ui::Switch *ui;
    QString stateSwitch;

signals:
    void activateSerialWrite_Switch();
};

#endif // SWITCH_H
