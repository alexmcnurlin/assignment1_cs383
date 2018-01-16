#ifndef PADDLE_H
#define PADDLE_H
#include <QGraphicsItem>
#include "paddlecontrol.h"
#include "ball.h"


class Paddle : public QGraphicsItem {
    public:
        Paddle(int x, int y, PaddleControl *pc);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

    private:
        int x;
        int y;
        int speed;
        PaddleControl* pc;

    protected:
        void advance(int step);
};


#endif
