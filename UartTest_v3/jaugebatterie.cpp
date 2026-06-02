#include "jaugebatterie.h"
#include <QPainter>
#include <QPolygon>

JaugeBatterie::JaugeBatterie(QWidget *parent)
    : QWidget{parent}
{

}

void JaugeBatterie::setValue(int v)
{
    b_value = qBound(0, v, 100);
    update();
}

void JaugeBatterie::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    QRect r = rect();

    //contour
    QRect body = r.adjusted(5, 5, -15, -5);
    QRect head(body.right(), body.height()/3, 10, body.height()/3);

    p.setPen(Qt::lightGray);
    p.drawRect(body);
    p.drawRect(head);

    //Couleur dynamique
    QColor color;
    if(b_value > 60)
        color = Qt::green;
    else if (b_value > 30)
        color = QColor(255, 165, 0); //pourquoi le orange n'existe pas dans QT ;-; ?
    else
        color = Qt::red;

    p.setBrush(color);
    p.setPen(Qt::NoPen);

    //Remplissage

    int width = (body.width() * b_value) / 100;
    QRect fill = body.adjusted(2, 2, -body.width() + width -2, -2);
    p.drawRect(fill);

}
