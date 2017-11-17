#ifndef OBJETOSMOVIBLES_H
#define OBJETOSMOVIBLES_H
#include <QGraphicsItem>
#include <QPainter>

class objetosMovibles: public QGraphicsItem
{
public:
    objetosMovibles();
    objetosMovibles(float posx, float posy);

   void boundingRect();
   void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
   void ActualizarPosicion(float t);

   void moverDiagonal(bool moverDi);

   float getPosx() const;
   void setPosx(float value);

   float getPosy() const;
   void setPosy(float value);

   bool getMoverD() const;
   void setMoverD(bool value);

public slots:
   void advance(int phace);

private:
   float posx,posy,vx,vy,ax,ay;

   bool moverD;


};

#endif // OBJETOSMOVIBLES_H
