#include "paddle.h"
#include "ball.h"
#include "usercontrol.h"
#include "computercontrol.h"
#include "wall.h"
#include "goal.h"
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

    Ball b(0, 0);

    UserControl uc(&view);
    Paddle p1(XDIM/2-5, 0, &uc);

    Goal g1(XDIM/2, 0, 5, YDIM, &b);
    Goal g2(-XDIM/2, 0, 5, YDIM, &b);

    ComputerControl cc(&b);
    Paddle p2(-XDIM/2+5, 0, &cc);

    Wall w1(0, -YDIM/2+5, XDIM, 10);
    Wall w2(0, YDIM/2-5, XDIM, 10);

    scene.addItem(&g1);
    scene.addItem(&g2);
    scene.addItem(&p1);
    scene.addItem(&p2);
    scene.addItem(&b);
    scene.addItem(&w1);
    scene.addItem(&w2);

    view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(5);

    return app.exec();
}
