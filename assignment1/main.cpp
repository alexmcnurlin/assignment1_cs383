#include "mainwindow.h"
#include "paddle.h"
#include "usercontrol.h"
#include "computercontrol.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtGui>
#include <math.h>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    qsrand(QTime::currentTime().msec());

    QGraphicsScene scene;
    scene.setSceneRect(-300, -300, 600, 600);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setWindowTitle("CS383 Assignment 1");

    UserControl *uc = new UserControl(&view);
    Paddle *p1 = new Paddle(100, 0, uc);
    scene.addItem(p1);

    ComputerControl *cc = new ComputerControl();
    Paddle *p2 = new Paddle(-100, 0, cc);
    scene.addItem(p2);

    view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(10);

    return app.exec();
}
