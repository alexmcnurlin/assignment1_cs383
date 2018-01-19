#include "goal.h"
#include "ball.h"
#include <QRectF>
#include <QPainter>
#include <QDebug>


Goal::Goal(int x_0, int y_0, int w_0, int h_0, Ball *b) {
    this->ball = b;
    this->x = x_0;
    this->y = y_0;
    this->w = w_0;
    this->h = h_0;
    this->score = 0;
    setPos(x, y);
}


QRectF Goal::boundingRect() const {
    return QRectF(-w/2., -h/2., w, h);
}


void Goal::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::white);
    painter->drawRect(QRectF(-w/2., -h/2., w, h));
}


void Goal::advance(int step) {
    QList<QGraphicsItem *> nearItems = collidingItems();
    foreach (QGraphicsItem *item, nearItems) {
        if (typeid(*item) == typeid(Ball)) {
            ball->reset_ball();
        }
    }
    setPos(x, y);
    update();
}
