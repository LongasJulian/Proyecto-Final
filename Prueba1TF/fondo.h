#ifndef FONDO_H
#define FONDO_H
//#include <QGraphicsItem>
//#include <QPainter>
//#include <objetosinamovibles3.h>

class fondo:public objetosinamovibles3
{
public:
    fondo();
        QRectF boundingRect() const;
        void paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget);
        void mover();
        //void colision();

        int vx;
};

#endif // FONDO_H
