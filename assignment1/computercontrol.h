#ifndef COMPC_H
#define COMPC_H
#include <QGraphicsItem>
#include <QTime>

#include "paddlecontrol.h"

class ComputerControl : public PaddleControl {
    public:
        ComputerControl(QGraphicsItem *b);
        int movePaddle(QPointF currentLocation);

    private:
        QGraphicsItem *followObject;
        QTime *time;
        int direction;
};

#endif
