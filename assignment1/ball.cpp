#include <QPainter>
#include <typeinfo>
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
        this->reflect(item);
        break;
    }

    this->x+=this->xVel;
    this->y+=this->yVel;
    this->setPos(this->x, this->y);
    update();
    this->setFocus(); //It's a hack, I know :/
}


void Ball::reflect(QGraphicsItem *p) {
    // I know it is bad design to include a typecheck here. I would rather
    // define a 'reflect' method on each item (Paddle, Wall, ect), but I'm given 
    // a list QGraphicsItems so the compiler won't let me do that, since 
    // QGraphicsItem does not have a 'reflect' method
    if (typeid(*p) == typeid(Paddle)) {
        QPointF pCoord = p->scenePos();
        float distance = pCoord.y() - this->y;
        float k = 0.03;
        this->yVel = this->yVel - (k*distance);
        this->xVel = -this->xVel;
    } else {
        this->yVel = -this->yVel;
    }
}
