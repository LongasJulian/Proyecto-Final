#ifndef OBJETOSPROYECTILES_H
#define OBJETOSPROYECTILES_H

#include <QGraphicsItem>
#include <QPainter>


class ObjetosProyectiles: public QGraphicsItem
{
public:
    ObjetosProyectiles();

    ObjetosProyectiles(float x, float y);
    void poscuerpo(float t);


    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);


    float getPosx() const;
    void setPosx(float value);
    float getPosy() const;
    void setPosy(float value);

    float getVelx() const;
    void setVelx(float value);

    float getVely() const;
    void setVely(float value);

    void moverafterC(bool movx);
    bool getBool_Choque() const;
    void setBool_Choque(bool value);

public slots:
    void advance(int phase);
private:
    bool Bool_Choque;
    float vx,vy,ax,ay;
    float step;
    float posx,posy,velx,vely,cont;
    int directiony,directionx;
    QPainter *pintador;
    //qreal angle;
    //QImage image;

};

#endif // OBJETOSPROYECTILES_H

//-------------Proyectiles Diagonal-----------//

class ProyectilesDiagonales: public ObjetosProyectiles
{
public:
    ProyectilesDiagonales();

    ProyectilesDiagonales(float x, float y);

    QRectF boundingRect() const;

    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);

    void ActualizarPosicion(float t);
    void choque(bool choque);

    float getPosy() const;
    void setPosy(float value);

    float getPosx() const;
    void setPosx(float value);

    bool getBool_Choque() const;
    void setBool_Choque(bool value);

private:
    QPainter *pintar;
    int step;
    bool bool_Choque,auxP;
    float lan,posy,posx,vx,vy,ax,ay;
public slots:
    void advance(int phase);

};
