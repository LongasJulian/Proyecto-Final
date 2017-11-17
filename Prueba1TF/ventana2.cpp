#include "ventana2.h"
#include "ui_ventana2.h"
#include <QDebug>

ventana2::ventana2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ventana2)
{
    cont=0;
    ui->setupUi(this);
    this->showMaximized();
    int time=0;
    //scene->addRect(100,100,10,10);
    scene=new QGraphicsScene(0,0,1100,450);
    ui->graphicsView->setScene(scene);
    l1=new QGraphicsLineItem(0,0,1100,0);
    l2=new QGraphicsLineItem(0,0,0,450);
    l3=new QGraphicsLineItem(1100,0,1100,450);
    l4=new QGraphicsLineItem(0,450,1100,450);

    scene->addItem(l1);
    scene->addItem(l2);
    scene->addItem(l3);
    scene->addItem(l4);

    aux=true;
    //scene->addItem(l5);

    mover1=false;
    moverD=false;
    num=qrand()%(10-1)+1;
    Proyectiles=false;
    off=true;
    //aux2=true;
    // TIMERS
    timer=new QTimer();
    timer1=new QTimer();
    timer2=new QTimer();
    timer3=new QTimer();
    timer4=new QTimer();
    timer5=new QTimer();
    connect(timer1,SIGNAL(timeout()),this,SLOT(animar()));
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(aparecer()));
    connect(timer3,SIGNAL(timeout()),this,SLOT(aparecer2()));
    connect(timer4,SIGNAL(timeout()),this,SLOT(tiempodejuego())) ;
    connect(timer5,SIGNAL(timeout()),this,SLOT(aparecer3()));
    timer->start(25);
    timer1->start(50);
    timer2->start(8000);
    timer3->start(10000);
    timer4->start(60000);
    timer5->start(7000);
//    timer2->start(1);
    //timer2->timeout(SLOT(ventana2::aparecer()));
    //QTimer::singleShot(10,this,SLOT(ventana2::aparecer()));
    time=time+1;
    //--------------------


//    obstaculo=new objetosinamovibles3();
//    scene->addItem(obstaculo);
//    obstaculo->setPos(1000,370);


    //----obstaculos--//
      obstaculo=new objetosinanimados3a1();
      scene->addItem(obstaculo);
      obstaculo->setPos(1000,410);
      obstaculo1=new objetosinanimados3a2();
      scene->addItem(obstaculo1);
      obstaculo1->setPos(400,350);
      obstaculo2=new objetosinanimados3a3();
      scene->addItem(obstaculo2);
      obstaculo2->setPos(700,200);
      obstaculo3=new objetosinanimados3a4a();
      scene->addItem(obstaculo3);
      obstaculo3->setPos(800,350);
      obstaculo4=new objetosinanimados3a5();
      scene->addItem(obstaculo4);
      obstaculo4->setPos(100,350);
      //----------//

      //----Proyectiles--//
      //proyectil =  new ObjetosProyectiles();
      //movy1=true;movy2=true;movy3=true;


      //----------//

      //---fondo--//


      //----------//


      //---PLAYER1---//
        Player1= new ObjetosMovibles3;
        scene->addItem(Player1);

      //------------//



}

ventana2::~ventana2()
{
    delete ui;
}

void ventana2::keyPressEvent(QKeyEvent *ev)
{

        if(ev->key()==Qt::Key_Space)
        {


            mover1=true;
                //aprecer();
        }
        if (ev->key()==Qt::Key_E)
        {
            moverD=true;
        }
        if (ev->key()==Qt::Key_D)
        {
            moverDer=true;
        }
    }


void ventana2::keyReleaseEvent(QKeyEvent *ev)
{

        if(ev->key()==Qt::Key_D)
        {

           moverDer=false;
        }
}

void ventana2::aparecer()
{


    //    qDebug() << "hola";
        proyectilD1=new ProyectilesDiagonales;
        scene->addItem(proyectilD1);
        proyectilD2=new ProyectilesDiagonales;
        scene->addItem(proyectilD2);
        proyectilD2=new ProyectilesDiagonales;
        scene->addItem(proyectilD2);
        proyectilD3=new ProyectilesDiagonales;
        scene->addItem(proyectilD3);


}

void ventana2::aparecer2()
{
        proyectil =  new ObjetosProyectiles(qrand()%(1000-5)+5,qrand()%(20-5)+5);
        scene->addItem(proyectil);
        proyectil1 =  new ObjetosProyectiles(qrand()%(1000-5)+5,qrand()%(20-5)+5);
        scene->addItem(proyectil1);
        proyectil2 =  new ObjetosProyectiles(qrand()%(1000-5)+5,qrand()%(20-5)+5);
        scene->addItem(proyectil2);

}

void ventana2::aparecer3()
{
}

void ventana2::tiempodejuego()
{
    off=false;
}

void ventana2::animar()
{
   //qDebug() << "13";
    if (mover1)
    {


        //----Obstaculos---//
        if (off)
        {
            obstaculo->mover();
            obstaculo1->mover();
            obstaculo2->mover();
            obstaculo3->mover();
            obstaculo4->mover();
        }
        // obstaculos
        if(obstaculo->collidesWithItem(l2) ||obstaculo->collidesWithItem(obstaculo1)
                || obstaculo->collidesWithItem(obstaculo2) ||obstaculo->collidesWithItem(obstaculo3) ||
                obstaculo->collidesWithItem(obstaculo4))
            {
                //num=qrand()%(10-1)+1;
                obstaculo->setPos(1050,410);
                obstaculo->colision();
          //      nubes->colision();

            }
        bool aux5=false;
        if (obstaculo->collidesWithItem(Player1))
        {
            if (Player1->getPosy()>=50)
            {
                Player1->setMover_Normal(true);
            }
        }
        if (!obstaculo->collidesWithItem(Player1) && Player1->getPosy()>=50)
        {
            //if ()

            //{
                //Player1->setMover_Dia(true);
                Player1->setGravedad(true);
            //}
        }


            if(obstaculo1->collidesWithItem(l2)||obstaculo1->collidesWithItem(obstaculo) ||
                    obstaculo1->collidesWithItem(obstaculo2)||obstaculo1->collidesWithItem(obstaculo3) ||
                    obstaculo1->collidesWithItem(obstaculo4))
            {

                obstaculo1->setPos(1000,350);
                obstaculo1->colision();
          //      nubes->colision();
                    //}
            }
            if(obstaculo4->collidesWithItem(l2)||obstaculo4->collidesWithItem(obstaculo1)
                    || obstaculo4->collidesWithItem(obstaculo) ||obstaculo4->collidesWithItem(obstaculo3) ||
                    obstaculo4->collidesWithItem(obstaculo2))
            {
               // aparecer();

                obstaculo4->setPos(1500,350);
                obstaculo4->colision();
            }

        if(obstaculo2->collidesWithItem(l2)||obstaculo2->collidesWithItem(obstaculo1)
                || obstaculo2->collidesWithItem(obstaculo) ||obstaculo2->collidesWithItem(obstaculo3) ||
                obstaculo2->collidesWithItem(obstaculo4))
        {

            obstaculo2->setPos(1100,350);
            obstaculo2->colision();
      //      nubes->colision();
                //}
        }
        if(obstaculo3->collidesWithItem(l2)||obstaculo3->collidesWithItem(obstaculo1)
                || obstaculo3->collidesWithItem(obstaculo) ||obstaculo3->collidesWithItem(obstaculo2) ||
                obstaculo3->collidesWithItem(obstaculo4))
        {
            obstaculo3->setPos(1300,350);
            obstaculo3->colision();

        }

        if(proyectil->collidesWithItem(l4) && movy1)
        {
            movy1=false;
            proyectil->moverafterC(true);
        }
        if(!proyectil1->collidesWithItem(l4))
            {
                movy1=true;
                proyectil2->moverafterC(false);
            }
        if(proyectil2->collidesWithItem(l4) && movy2)
        {
            movy2=false;
            proyectil2->moverafterC(true);
         }
        if(!proyectil2->collidesWithItem(l4))
            {
                movy2=true;
                proyectil2->moverafterC(false);
            }
            if(proyectil1->collidesWithItem(l4) && movy3)
            {

                movy3=false;
                proyectil1->moverafterC(true);
            }
            if(!proyectil1->collidesWithItem(l4))
            {

                movy3=true;
                proyectil1->moverafterC(false);
            }
            if(proyectilD1->collidesWithItem(l4) && auxD1)
            {
                proyectilD1->choque(true);
                auxD1=false;
            }
            if(!(proyectilD1->collidesWithItem(l4)))
            {
                proyectilD1->choque(false);
                auxD1=true;
            }
            if(proyectilD2->collidesWithItem(l4) && auxD2)
            {
                proyectilD2->choque(true);
                auxD2=false;
            }
            if(!(proyectilD2->collidesWithItem(l4)))
            {
                proyectilD2->choque(false);
                auxD2=true;
            }
            if(proyectilD3->collidesWithItem(l4) && auxD3)
            {
                proyectilD3->choque(true);
                auxD3=false;
            }
            if(!(proyectilD3->collidesWithItem(l4)))
            {
                proyectilD3->choque(false);
                auxD3=true;
            }
        }
        // Objetos Movibles

        if (moverD)
        {
            Player1->setMover_Dia(true);
            moverD=false;
            Player1->setGravedad(false);

        }
        if (Player1->collidesWithItem(l4))
        {
            qDebug()<<"asfasdfasdfasf";
            Player1->setNocolision(true);
            Player1->setGravedad(false);
        }
        if (moverDer)
        {
            Player1->setMover_Der(true);
       //     moverDer=false;
        }





    }



