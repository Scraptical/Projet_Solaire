#ifndef TESTUNITAIRE_1_H
#define TESTUNITAIRE_1_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TestUnitaire_1; }
QT_END_NAMESPACE

class TestUnitaire_1 : public QMainWindow
{
    Q_OBJECT

public:
    TestUnitaire_1(QWidget *parent = nullptr);
    ~TestUnitaire_1();

private:
    Ui::TestUnitaire_1 *ui;
};
#endif // TESTUNITAIRE_1_H
