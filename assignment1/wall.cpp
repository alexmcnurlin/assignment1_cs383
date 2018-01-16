#include "wall.h"
#include "paddle.h"
#include <QRectF>


Wall::Wall(int x, int y, int w, int h) {
    this->setPos(x, y);
    this->w = w;
    this->h = h;
}


QRectF Wall::boundingRect() const {
    return QRectF(-this->w/2., -this->h/2., this->w, this->h);
}


void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->setBrush(Qt::black);
    painter->drawRect(QRectF(-this->w/2., -this->h/2., this->w, this->h));
}
