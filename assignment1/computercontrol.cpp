#include "computercontrol.h"
#include <QTime>

ComputerControl::ComputerControl(QGraphicsItem *b) {
    this->followObject = b;
    this->time = new QTime();
    this->time->start();
    this->direction = 0;
};

int ComputerControl::movePaddle(QPointF currentLocation) {
    if (time->elapsed() > 100) {
        qreal myY = currentLocation.y();
        qreal followY = followObject->scenePos().y();
        if (abs(followY - myY) < 5) {
            return 0;
        } else if (followY > myY) {
            direction = 1;
        } else {
            direction = -1;
        }
        time->restart();
    }
    return direction;
}
