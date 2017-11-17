#ifndef VENTANA2_H
#define VENTANA2_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QTimer>
#include <QTimerEvent>
#include <objetosinamovibles3.h>
#include <objetosproyectiles.h>
#include <objetosmovibles3.h>

namespace Ui {
class ventana2;
}

class ventana2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit ventana2(QWidget *parent = 0);
    ~ventana2();
    QGraphicsScene* scene;
    QGraphicsLineItem* l1;
    QGraphicsLineItem* l2;
    QGraphicsLineItem* l3;
    QGraphicsLineItem* l4;
    QGraphicsLineItem* le1;
    QGraphicsLineItem* le2;
    QGraphicsLineItem* le3;

    //Obstaculos

    objetosinamovibles3* obstaculo;
    objetosinamovibles3* obstaculo1;
    objetosinamovibles3* obstaculo2;
    objetosinamovibles3* obstaculo3;
    objetosinamovibles3* obstaculo4;

    //Proyectiles

    ObjetosProyectiles *proyectil,*proyectil1,*proyectil2;
    ProyectilesDiagonales *proyectilD1;
    ProyectilesDiagonales *proyectilD2;
    ProyectilesDiagonales *proyectilD3;


    //Player1

    ObjetosMovibles3 *Player1;

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
    void aprecer();
    float num;
    int cont;
    bool mover1,mover,Proyectiles,off,aux,auxD1,auxD2,auxD3;
    bool movy1,movy2,movy3;

    bool moverD,moverDer;

    QTimer *timer, *timer1, *timer2, *timer3, *timer4, *timer5;

private:
    Ui::ventana2 *ui;
public slots:
    void animar();
     void aparecer();
     void aparecer2();
     void aparecer3();
     void tiempodejuego();
     //void animaproyectiles();

private slots:
    //void aparecer();


};

#endif // VENTANA2_H
