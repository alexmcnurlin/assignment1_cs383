#include "mainwindow.h"
#include "paddle.h"
#include "ball.h"
#include "usercontrol.h"
#include "computercontrol.h"
#include "wall.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtGui>
#include <math.h>

#define XDIM 600
#define YDIM 600

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    qsrand(QTime::currentTime().msec());

    QGraphicsScene scene;
    scene.setSceneRect(-XDIM/2, -YDIM/2, XDIM, YDIM);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setWindowTitle("CS383 Assignment 1");

    UserControl uc(&view);
    Paddle p1(XDIM/2-5, 0, &uc);
    scene.addItem(&p1);

    Ball b(0, 0);
    scene.addItem(&b);

    ComputerControl cc(&b);
    Paddle p2(-XDIM/2+5, 0, &cc);
    scene.addItem(&p2);

    Wall w1(0, YDIM/2-5, XDIM, 10);
    Wall w2(0, -YDIM/2+5, XDIM, 10);
    scene.addItem(&w1);
    scene.addItem(&w2);


    view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(10);

    return app.exec();
}
