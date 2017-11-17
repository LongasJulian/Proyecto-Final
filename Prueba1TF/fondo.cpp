#include "fondo.h"

fondo::fondo()
{
    vx=0.2;
}

QRectF fondo::boundingRect() const
{
   return QRectF(0,0,50,50);
}

void fondo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load("//home/longas/Documentos/Informática II/TrabajoFinal/trabajofinalPrueba1/Trabajo Final/Nube.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void fondo::mover()
{
 setPos(x()+vx,y());
}
