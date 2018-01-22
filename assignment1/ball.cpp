#include <QPainter>
#include <typeinfo>
#include <QGraphicsScene>
#include <QApplication>
#include "ball.h"
#define SIZEX 10
#define SIZEY 10


Ball::Ball(qreal x, qreal y) { 
    this->reset_ball();
}


QRectF Ball::boundingRect() const {
    return QRectF(-SIZEX/2., -SIZEY/2., SIZEX, SIZEY);
}


void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->setBrush(Qt::black);
    painter->drawRect(QRectF(-SIZEX/2., -SIZEY/2., SIZEX, SIZEY));
}


void Ball::reset_ball() {
    x = 0;
    y = 0;
    xVel = 1. * (double)(qrand() % 2 - .5);
    yVel = ((qrand() % 100) - 50)/1500.0;
    setPos(x, y);
}


void Ball::advance(int step) {
    if (!step)
        return;

    QList<QGraphicsItem *> nearItems = collidingItems();
    foreach (QGraphicsItem *item, nearItems) {
        reflect(item);
        break;
    }

    x+=xVel;
    y+=yVel;
    setPos(x, y);
    update();
}


void Ball::reflect(QGraphicsItem *p) {
    // I know it is bad design to include a typecheck here, however I couldn't think of a better way to do this with the way I detect collisions.
    if (typeid(*p) == typeid(Paddle)) {
        QPointF pCoord = p->scenePos();
        float distance = pCoord.y() - y;
        float k = 0.015;
        yVel = yVel - (k*distance);
        xVel = -xVel*1.1;
    } else {
        yVel = -yVel;
    }
}
