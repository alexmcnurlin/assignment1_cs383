#ifndef PADC_H
#define PADC_H
#include <QPointF>

class PaddleControl {
    public:
        PaddleControl();
        virtual int movePaddle(QPointF currentLocation);
};

#endif
