#include "computercontrol.h"
#include <QTime>

ComputerControl::ComputerControl(QGraphicsItem *b) {
    this->followObject = b;
    this->time = new QTime();
    this->time->start();
    this->direction = 0;
};

int ComputerControl::movePaddle(QPointF currentLocation) {
    if (this->time->elapsed() > 30) {
        qreal myY = currentLocation.y();
        qreal followY = followObject->scenePos().y();
        if (followY > myY) {
            this->direction = 1;
        } else {
            this->direction = -1;
        }
        this->time->restart();
    }
    return direction;
}
