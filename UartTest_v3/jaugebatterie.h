#ifndef JAUGEBATTERIE_H
#define JAUGEBATTERIE_H

#include <QWidget>
#include <QPainter>
#include <QPolygon>


class JaugeBatterie : public QWidget
{
    Q_OBJECT
public:
    explicit JaugeBatterie(QWidget *parent = nullptr);

    void setValue(int v);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int b_value;
};

#endif // JAUGEBATTERIE_H
