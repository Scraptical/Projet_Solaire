#ifndef JAUGEECLAIR_H
#define JAUGEECLAIR_H

#include <QWidget>
#include <QPainter>
#include <QPolygon>


class JaugeEclair : public QWidget
{
    Q_OBJECT
public:
    explicit JaugeEclair(QWidget *parent = nullptr);

    void setValue(double v); // 0 → 100

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    double value = 0;


};

#endif JAUGEECLAIR_H
