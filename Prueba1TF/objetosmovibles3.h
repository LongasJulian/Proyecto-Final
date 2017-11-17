#ifndef OBJETOSMOVIBLES3_H
#define OBJETOSMOVIBLES3_H
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>

class ObjetosMovibles3: public QGraphicsItem
{
public:
    ObjetosMovibles3();
    ObjetosMovibles3(float x , float y);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);

    void ActualizarPosicion(float t);
    void Colisionsuelo();
    void Mover_Diagonal();
    void Mover_Normalf();
    void Mover_Nocolison();
    void Mover_Gravedad();
    void Mover_Derecha();

    float getPosx() const;
    void setPosx(float value);

    float getPosy() const;
    void setPosy(float value);

    float getVx() const;
    void setVx(float value);

    float getVy() const;
    void setVy(float value);

    bool getMover_Dia() const;
    void setMover_Dia(bool value);

    bool getMover_Normal() const;
    void setMover_Normal(bool value);

    bool getNocolision() const;
    void setNocolision(bool value);

    bool getGravedad() const;
    void setGravedad(bool value);

    bool getMover_Der() const;
    void setMover_Der(bool value);

private:
    float posx,posy,vx,vy,ax,ay;
    bool Mover_Dia, Mover_Up, Mover_Der, Mover_Iz, Mover_Normal,nocolision,
        Gravedad;

protected slots:
    void advance(int phase);

};

#endif // OBJETOSMOVIBLES3_H
