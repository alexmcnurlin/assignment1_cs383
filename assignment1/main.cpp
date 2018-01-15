#include "mainwindow.h"
#include "paddle.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtGui>
#include <math.h>

/* static const int MouseCount = 7; */

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    qsrand(QTime::currentTime().msec());

    QGraphicsScene scene;
    scene.setSceneRect(-300, -300, 600, 600);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    Paddle *p1 = new Paddle;
    scene.addItem(p1);

    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setWindowTitle("CS383 Assignment 1");
    view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(10);

    return app.exec();
}
