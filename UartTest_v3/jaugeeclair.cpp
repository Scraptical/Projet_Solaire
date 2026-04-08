#include "jaugeeclair.h"
#include <QPainter>
#include <QPolygon>

JaugeEclair::JaugeEclair(QWidget *parent)
    : QWidget{parent}
{

}

void JaugeEclair::setValue(double v)
{
    value = qBound(0.0, v, 100.0);
    update();
}

void JaugeEclair::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    QRect r = rect();

    //Forme d'éclair (points)
    QPolygon lightning;
    lightning << QPoint(r.width()*0.6, 0)
              << QPoint(r.width()*0.3, r.height()*0.5)
              << QPoint(r.width()*0.5, r.height()*0.5)
              << QPoint(r.width()*0.3, r.height())
              << QPoint(r.width()*0.7, r.height()*0.4)
              << QPoint(r.width()*0.5, r.height()*0.4);

    //Dessin fond (gris)
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::lightGray);
    p.drawPolygon(lightning);

    //Clip pour remplissage
    p.setClipRegion(QRegion(lightning));

    //Hauteur de remplissage
    int fillHeight = r.height() * (value / 100.0);

    QRect fillRect(0, r.height() - fillHeight,
                   r.width(), fillHeight);

    //Couleur dynamique
    QColor color;
    if(value < 30)
        color = Qt::red;
    else if(value < 70)
        color = Qt::yellow;
    else
        color = Qt::green;

    p.setBrush(color);
    p.drawRect(fillRect);

    p.setClipping(false);

    //contour
    p.setPen(QPen(Qt::black, 2));
    p.setBrush(Qt::NoBrush);
    p.drawPolygon(lightning);
}
