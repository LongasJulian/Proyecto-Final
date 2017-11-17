#ifndef OBJETOSINAMOVIBLES3_H
#define OBJETOSINAMOVIBLES3_H

#include <QGraphicsItem>
#include <QPainter>


class objetosinamovibles3: public QGraphicsItem
{
public:
    objetosinamovibles3();
    void mover();
    void colision();

    int vx;
};

#endif // OBJETOSINAMOVIBLES3_H

//______________OBJETO-1__________________//
#ifndef OBJETOSINANIMADOS3A1_H
#define OBJETOSINANIMADOS3A1_H

class objetosinanimados3a1:public objetosinamovibles3
{
public:
    objetosinanimados3a1();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif // OBJETOSINANIMADOS3A1_H
//_______________________________________//

//______________OBJETO-2__________________//

#ifndef OBJETOSINANIMADOS3A2_H
#define OBJETOSINANIMADOS3A2_H
#include <objetosinamovibles3.h>



class objetosinanimados3a2:public objetosinamovibles3
{
public:
    objetosinanimados3a2();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // OBJETOSINANIMADOS3A2_H
//___________________________________________//

//______________OBJETO-3__________________//

#ifndef OBJETOSINANIMADOS3A3_H
#define OBJETOSINANIMADOS3A3_H
#include <objetosinamovibles3.h>

class objetosinanimados3a3:public objetosinamovibles3
{
public:
    objetosinanimados3a3();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // OBJETOSINANIMADOS3A3_H


//___________________________________________//

//______________OBJETO-4__________________//
#ifndef OBJETOSINANIMADOS3A4A_H
#define OBJETOSINANIMADOS3A4A_H
#include <objetosinamovibles3.h>

class objetosinanimados3a4a:public objetosinamovibles3
{
public:
    objetosinanimados3a4a();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // OBJETOSINANIMADOS3A4A_H


//___________________________________________//

//______________OBJETO-5__________________//
#ifndef OBJETOSINANIMADOS3A5_H
#define OBJETOSINANIMADOS3A5_H
#include <objetosinamovibles3.h>

class objetosinanimados3a5:public objetosinamovibles3
{
public:
    objetosinanimados3a5();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // OBJETOSINANIMADOS3A5_H

//___________________________________________//

//______________**FONDO**____________________//
//_______ NUBE (activador 1)_________________//
#ifndef FONDO_H
#define FONDO_H
class fondo:public objetosinamovibles3
{
public:
    int l,a;
    fondo();
        QRectF boundingRect() const;
        void paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget);
        void mover();
        //void colision();

        int vx;
};

#endif // FONDO_H

//____________________________________________//
