#include <QPainter>
#include <QApplication>
#include <QKeyEvent>
#include "paddle.h"
#include "paddlecontrol.h"
#include "ball.h"
#define SIZEX 10
#define SIZEY 100


Paddle::Paddle(int x, int y, PaddleControl *pc) { 
    this->pc = pc;
    this->x = x;
    this->y = y;
    this->speed = 1;
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
    this->y+=this->speed*this->pc->movePaddle(this->scenePos());
    this->setPos(this->x, this->y);
    update();
}
