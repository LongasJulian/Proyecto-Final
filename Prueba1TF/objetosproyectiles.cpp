#include "objetosproyectiles.h"
#include <QDebug>
#include <QGraphicsScene>
ObjetosProyectiles::ObjetosProyectiles()
{

//    angle=(qrand() % 360);
//    setRotation(angle);

    setPosx((qrand() %(1000-1)+1));
    setPosy((qrand() % (20-10)+10));
    vx=0;
    step=(qrand()%(3-1)+1);
    vy=-step;
    ax=0;
    ay=(9.8-(0.78));
    Bool_Choque=false;
    step=0;
    //vy=-50;

    pintador =  new QPainter();
    //-----//

}

ObjetosProyectiles::ObjetosProyectiles(float x, float y)
{
    //angle=(qrand()%180);
    setPosx(x);
    setPosy(y);
    this->setPos(x,y);
    //direction=1;
    step=0;
    pintador =  new QPainter();
    vx=0;
    step=(qrand()%(3-1)+1);
    vy=-step;
    ax=0;
    ay=(9.8-(0.78));
    Bool_Choque=false;


}

void ObjetosProyectiles::poscuerpo(float t)
{
    vx= vx + ax*t;
    posx= posx + vx*t + (ax*(t*t))/2;

    vy = vy + ay*t;
    posy= posy + vy*t + (ay*(t*t))/2;

}

QRectF ObjetosProyectiles::boundingRect() const
{
    return QRectF(0,0,25,25);

}

void ObjetosProyectiles::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec =  boundingRect();

    QBrush Brush(Qt::red);

    painter->setBrush(Qt::red);
    painter->drawEllipse(rec);
    //painter->fillRect(rec,Brush);
    pintador = painter;

}

float ObjetosProyectiles::getPosx() const
{
    return posx;
}

void ObjetosProyectiles::setPosx(float value)
{
    posx = value;
}

float ObjetosProyectiles::getPosy() const
{
    return posy;
}

void ObjetosProyectiles::setPosy(float value)
{
    posy = value;
}

void ObjetosProyectiles::advance(int phase)
{
//    vx=qrand()%(5-1)+1;
//    vy=qrand()%(5-1)+1;

    //qDebug() << step;
    if(phase==0) return;
    else{
//        poscuerpo(0.1);
//        this->setPos(getPosx(),getPosy());


        if(Bool_Choque==false)
        {
           //qDebug()<<"cafe";
            poscuerpo(0.1);
            this->setPos(getPosx(),getPosy());
        }
        else if(Bool_Choque)
        {
            //qDebug()<<"con leche";
            vy=-vy/1.5;
            vx=vx-10;
            poscuerpo(0.1);
            this->setPos(getPosx(),getPosy());
            Bool_Choque=false;
        }
    }


}

bool ObjetosProyectiles::getBool_Choque() const
{
    return Bool_Choque;
}

void ObjetosProyectiles::setBool_Choque(bool value)
{
    Bool_Choque = value;
}

float ObjetosProyectiles::getVely() const
{
    return vely;
}

void ObjetosProyectiles::setVely(float value)
{
    vely = value;
}

void ObjetosProyectiles::moverafterC(bool movx)
{
    setBool_Choque(movx);
}

float ObjetosProyectiles::getVelx() const
{
    return velx;
}

void ObjetosProyectiles::setVelx(float value)
{
    velx = value;
}

//-------- Proyectiles Diagonales-------//

ProyectilesDiagonales::ProyectilesDiagonales()
{
    setPosx(1000);
    setPosy(100);
    vx=-(qrand()%(70-1)+1);
    lan=(qrand()%(70-1)+1);
    vy=-1*lan;
    ax=-0.0075;
    ay=(9.8-(0.78));
    auxP=true;
    bool_Choque=false;
}
ProyectilesDiagonales::ProyectilesDiagonales(float x, float y)
{
    setPosx(x);
    setPosy(y);
    this->setPos(x,y);
}

QRectF ProyectilesDiagonales::boundingRect() const
{
    return QRectF(0,0,25,25);
}

void ProyectilesDiagonales::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec =  boundingRect();
    pintar = painter;
    painter->setBrush(Qt::black);
    painter->drawEllipse(rec);

}

void ProyectilesDiagonales::ActualizarPosicion(float t)
{
    vx= vx + ax*t;
    posx= posx + vx*t + (ax*(t*t))/2;

    vy = vy + ay*t;
    posy= posy + vy*t + (ay*(t*t))/2;
}

void ProyectilesDiagonales::choque(bool choque)
{
 if(choque)
     setBool_Choque(choque);
 else
     setBool_Choque(choque);

}

float ProyectilesDiagonales::getPosy() const
{
    return posy;
}

void ProyectilesDiagonales::setPosy(float value)
{
    posy = value;
}

float ProyectilesDiagonales::getPosx() const
{
    return posx;
}

void ProyectilesDiagonales::setPosx(float value)
{
    posx = value;
}

bool ProyectilesDiagonales::getBool_Choque() const
{
    return bool_Choque;
}

void ProyectilesDiagonales::setBool_Choque(bool value)
{
    bool_Choque = value;
}

void ProyectilesDiagonales::advance(int phase)
{
    //qDebug()<<"hola";

    if(phase==0) return;
    else
    {/*
        ActualizarPosicion(0.1);
        this->setPos(getPosx(),getPosy());*/
        if(bool_Choque==false)
        {
//            lan=lan/0.5;
//            vy=-lan;
            ActualizarPosicion(0.1);
            this->setPos(getPosx(),getPosy());
           // qDebug()<< vy;
        }
        else if(bool_Choque)
        {


            lan=lan/1.1;
            vy=-lan;
            //vx=vx+3;
            ActualizarPosicion(0.1);
            this->setPos(getPosx(),getPosy());
            bool_Choque=false;


        }
//        else if(auxP)
//        {
//            ActualizarPosicion(0.1);
//            this->setPos(getPosx(),getPosy());
//            auxP=false;
//        }
    }
}

