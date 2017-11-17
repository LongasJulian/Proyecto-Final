#include "objetosmovibles3.h"

ObjetosMovibles3::ObjetosMovibles3()
{

    setPosx(10);
    setPosy(400);
    setVx(0);
    setVy(0);
    ax=0;
    ay=0;
    this->setPos(10,400);
    Mover_Dia=false;
    Mover_Normal=false;
    Gravedad=false;
}

ObjetosMovibles3::ObjetosMovibles3(float x, float y)
{

    setPosx(x);
    setPosy(y);
    setVx(0);
    setVy(0);
    ax=0;
    ay=0;
    this->setPos(x,y);
    Mover_Normal=false;
    Mover_Dia=false;
    Gravedad=false;
}

QRectF ObjetosMovibles3::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void ObjetosMovibles3::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load("//home/longas/Documentos/Informática II/TrabajoFinal/trabajofinalPrueba1/Trabajo Final/obstaculo2.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void ObjetosMovibles3::ActualizarPosicion(float t)
{
    vx= vx + ax*t;
    posx= posx + vx*t + (ax*(t*t))/2;

    vy = vy + ay*t;
    posy= posy + vy*t + (ay*(t*t))/2;
}

void ObjetosMovibles3::Mover_Diagonal()
{
    if (Mover_Dia)
    {
        Gravedad=false;
        vy=-50;
        vx=20;
        ax=0;
        ay=10;
    }
}

void ObjetosMovibles3::Mover_Normalf()
{
    if (Mover_Normal)
    {
        vx=-3;
        vy=0;
        ax=0;
        ay=0;
    }
}

void ObjetosMovibles3::Mover_Nocolison()
{
    if (nocolision)
    {
        vx=-3;
        vy=0;
        ax=0;
        ay=0;
    }
}

void ObjetosMovibles3::Mover_Gravedad()
{
    if (Gravedad)
    {
        ay=9.8;
    }
}

void ObjetosMovibles3::Mover_Derecha()
{
    if (Mover_Der)
    {
        vx=6;
        vy=0;
        ax=0;
        ay=0;
    }
}

float ObjetosMovibles3::getPosx() const
{
    return posx;
}

void ObjetosMovibles3::setPosx(float value)
{
    posx = value;
}

float ObjetosMovibles3::getPosy() const
{
    return posy;
}

void ObjetosMovibles3::setPosy(float value)
{
    posy = value;
}

float ObjetosMovibles3::getVx() const
{
    return vx;
}

void ObjetosMovibles3::setVx(float value)
{
    vx = value;
}

float ObjetosMovibles3::getVy() const
{
    return vy;
}

void ObjetosMovibles3::setVy(float value)
{
    vy = value;
}

bool ObjetosMovibles3::getMover_Dia() const
{
    return Mover_Dia;
}

void ObjetosMovibles3::setMover_Dia(bool value)
{
    Mover_Dia = value;
}

bool ObjetosMovibles3::getMover_Normal() const
{
    return Mover_Normal;
}

void ObjetosMovibles3::setMover_Normal(bool value)
{
    Mover_Normal = value;
}

bool ObjetosMovibles3::getNocolision() const
{
    return nocolision;
}

void ObjetosMovibles3::setNocolision(bool value)
{
    nocolision = value;
}

bool ObjetosMovibles3::getGravedad() const
{
    return Gravedad;
}

void ObjetosMovibles3::setGravedad(bool value)
{
    Gravedad = value;
}

bool ObjetosMovibles3::getMover_Der() const
{
    return Mover_Der;
}

void ObjetosMovibles3::setMover_Der(bool value)
{
    Mover_Der = value;
}

void ObjetosMovibles3::advance(int phase)
{
    //qDebug() << "si";
    if (phase==0);
    else
    {
        if (Mover_Der)
        {
            Mover_Derecha();
            Mover_Der=false;
        }
        if(nocolision)
        {
            Mover_Nocolison();

        }
        if(Mover_Dia)
        {
            Gravedad=false;
            nocolision=false;
            Mover_Diagonal();
            Mover_Dia=false;
        }
        if (Mover_Normal)
        {
            nocolision=false;
            Gravedad=false;
            Mover_Normalf();
            Mover_Normal=false;
        }
        if (Gravedad)
        {
            nocolision=false;
            Mover_Gravedad();
            Mover_Dia=false;
            Gravedad=false;
        }
        qDebug() << "cafe";
        ActualizarPosicion(0.1);
        qDebug() << vy;
        //qDebug() << getPosx();
        //qDebug() << getPosy();
        this->setPos(getPosx(),getPosy());

    }
}
