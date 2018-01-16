#include <QPainter>
#include <QGraphicsScene>
#include <QApplication>
#include "ball.h"
#include "collisionobject.h"
#define SIZEX 10
#define SIZEY 10


Ball::Ball(qreal x, qreal y) { 
    this->x = x;
    this->y = y;
    this->xVel = 1;
    this->yVel = 0;
}


Ball::~Ball() {};


QRectF Ball::boundingRect() const {
    return QRectF(-SIZEX/2., -SIZEY/2., SIZEX, SIZEY);
}


void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->setBrush(Qt::blue);
    painter->drawRect(QRectF(-SIZEX/2., -SIZEY/2., SIZEX, SIZEY));
}


void Ball::advance(int step) {
    if (!step)
        return;

    QList<QGraphicsItem *> nearItemsX = scene()->items(QRectF(this->x-SIZEX/2, this->y-SIZEY/2,
                                                       SIZEX, 1));
    foreach (QGraphicsItem *item, nearItemsX) {
        if (item == this)
            continue;
        this->reflectX(item);
        break;
    }

    QList<QGraphicsItem *> nearItemsY = scene()->items(QRectF(this->x-SIZEX/2, this->y-SIZEY/2,
                                                       1, SIZEY));
    foreach (QGraphicsItem *item, nearItemsY) {
        if (item == this)
            continue;
        this->reflectY(item);
        break;
    }

    this->x+=this->xVel;
    this->y+=this->yVel;
    this->setPos(this->x, this->y);
    update();
    this->setFocus(); //It's a hack, I know :/
}


void Ball::reflectX(QGraphicsItem *p) {
    QPointF pCoord = p->scenePos();
    float distance = pCoord.y() - this->y;
    float k = 0.03;
    this->yVel = this->yVel - (k*distance);
    this->xVel = -this->xVel;
}

void Ball::reflectY(QGraphicsItem *p) {
    this->yVel = -this->yVel;
}
