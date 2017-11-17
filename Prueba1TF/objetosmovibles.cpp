#include "objetosmovibles.h"

objetosMovibles::objetosMovibles()
{
    setPosx(50);
    setPosy(410);
    //this->setPos(getPosx(),getPosy());
    vx=-50;
    //lan=(qrand()%(25-1)+1);
    vy=-50;
    ax=0.75;
    ay=(9.8-(0.78));


}

objetosMovibles::objetosMovibles(float posx, float posy)
{
    setPosx(posx);
    setPosy(posy);
    //this->setPos(getPosx(),getPosy());
    vx=-50;
    //lan=(qrand()%(25-1)+1);
    vy=-50;
    ax=0.75;
    ay=(9.8-(0.78));

}

void objetosMovibles::boundingRect()
{
//    return QRectF(0,0,45,45);
}

void objetosMovibles::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//        QPixmap pixmap;
//        pixmap.load("/home/longas/Documentos/Informática II/TrabajoFinal/trabajofinalPrueba1/Trabajo Final/Cuadrado1.png");
//        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void objetosMovibles::ActualizarPosicion(float t)
{
    vx= vx + ax*t;
    posx= posx + vx*t + (ax*(t*t))/2;

    vy = vy + ay*t;
    posy= posy + vy*t + (ay*(t*t))/2;
}

void objetosMovibles::moverDiagonal(bool moverDi)
{
    this->setMoverD(moverDi);
}

void objetosMovibles::advance(int phace)
{
    if(phace==0)
    {}
    else
    {
        if (moverD)
        {
        ActualizarPosicion(0.1);
        this->setPos(getPosx(),getPosy());
        }
    }
}



bool objetosMovibles::getMoverD() const
{
    return moverD;
}

void objetosMovibles::setMoverD(bool value)
{
    moverD = value;
}

float objetosMovibles::getPosy() const
{
    return posy;
}

void objetosMovibles::setPosy(float value)
{
    posy = value;
}

float objetosMovibles::getPosx() const
{
    return posx;
}

void objetosMovibles::setPosx(float value)
{
    posx = value;
}
