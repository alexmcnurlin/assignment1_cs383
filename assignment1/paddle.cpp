#include <QPainter>
#include <QApplication>
#include <QKeyEvent>
#include "paddle.h"
/* #define WINDOW_MAX 270 */
#define SIZEX 10
#define SIZEY 100


Paddle::Paddle() { 
    this->x = 0;
    this->y = 0;
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
    if (!(qrand() % 100)) {
        speed = -speed;
    }
    this->y+=this->speed;
    this->setPos(this->x, this->y);
    update();
}
