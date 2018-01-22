#include <QPainter>
#include <QApplication>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QString>
#include <typeinfo>
#include "paddle.h"
#include "paddlecontrol.h"
#include "ball.h"
#include "wall.h"
#define SIZEX 10
#define SIZEY 100


Paddle::Paddle(int x, int y, PaddleControl *pc) { 
    this->pc = pc;
    this->x = x;
    this->y = y;
    this->speed = 1.5;
}


QRectF Paddle::boundingRect() const {
    return QRectF(-SIZEX/2., -SIZEY/2., SIZEX, SIZEY);
}


void Paddle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->setBrush(Qt::black);
    painter->drawRect(QRectF(-SIZEX/2., -SIZEY/2., SIZEX, SIZEY));
}


void Paddle::advance(int step) {
    if (!step)
        return;
    QRectF nextLocation = boundingRect();
    float dy = speed*pc->movePaddle(scenePos());
    nextLocation.translate(0, dy);

    QList<QGraphicsItem *> nearItems = scene()->items(mapToScene(nextLocation));
    foreach (QGraphicsItem *item, nearItems) {
        if (typeid(*item) == typeid(Wall)) {
            // This means the paddle is hitting a wall, so don't change the paddle's position
            return;
        }
        break;
    }
    y+=dy;
    setPos(x, y);
    update();
}
