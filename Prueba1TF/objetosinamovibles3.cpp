#include "objetosinamovibles3.h"

objetosinamovibles3::objetosinamovibles3()
{
    vx=10;
}

//QRectF objetosinamovibles3::boundingRect() const
//{
//    return QRectF(0,0,100,100);
//}

//void objetosinamovibles3::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    QPixmap pixmap;
//    pixmap.load("//home/longas/Documentos/Informática II/TrabajoFinal/trabajofinalPrueba1/Trabajo Final/Cuadrado123.png");
//    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
//}

void objetosinamovibles3::mover()
{
    vx=qrand()%(5-2)+2;
    setPos(x()-vx,y());
}

void objetosinamovibles3::colision()
{
    vx=vx/qrand()%(5-2)+2;
}
//#include "objetosinanimados3a1.h"

//______________OBJETO-1__________________//

objetosinanimados3a1::objetosinanimados3a1()
{

}

QRectF objetosinanimados3a1::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void objetosinanimados3a1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load("//home/longas/Documentos/Informática II/TrabajoFinal/trabajofinalPrueba1/Trabajo Final/Cuadrado123.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
//___________________________________________//


//______________OBJETO-2______________________//
objetosinanimados3a2::objetosinanimados3a2()
{

}

QRectF objetosinanimados3a2::boundingRect() const
{
    return QRectF(0,0,50,100);
}

void objetosinanimados3a2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load("//home/longas/Documentos/Informática II/TrabajoFinal/trabajofinalPrueba1/Trabajo Final/obstaculo.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

//___________________________________________//



//______________OBJETO-3______________________//
objetosinanimados3a3::objetosinanimados3a3()
{
    vx=5;
}

QRectF objetosinanimados3a3::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void objetosinanimados3a3::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load("//home/longas/Documentos/Informática II/TrabajoFinal/trabajofinalPrueba1/Trabajo Final/obstaculo2.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
//___________________________________________//


//______________OBJETO-4______________________//
objetosinanimados3a4a::objetosinanimados3a4a()
{

}
QRectF objetosinanimados3a4a::boundingRect() const
{
    return QRectF(0,0,100,50);
}

void objetosinanimados3a4a::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load("//home/longas/Documentos/Informática II/TrabajoFinal/trabajofinalPrueba1/Trabajo Final/obstaculo.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
//___________________________________________//


//______________OBJETO-5______________________//
objetosinanimados3a5::objetosinanimados3a5()
{

}
QRectF objetosinanimados3a5::boundingRect() const
{
    return QRectF(0,0,200,100);
}

void objetosinanimados3a5::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load("//home/longas/Documentos/Informática II/TrabajoFinal/trabajofinalPrueba1/Trabajo Final/obstaculo2.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

//___________________________________________//

//______________**FONDO**____________________//
//_______ NUBE (activador 1)_________________//
fondo::fondo()
{
    l=qrand()%(100-50)+50;
    a=qrand()%(100-50)+50;
    vx=1;
}

QRectF fondo::boundingRect() const
{
   return QRectF(0,0,l,a);
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
//____________________________________________//
