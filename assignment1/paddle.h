#ifndef PADDLE_H
#define PADDLE_H
#include <QGraphicsObject>
#include "paddlecontrol.h"
#include "ball.h"


class Paddle : public QGraphicsObject {
    public:
        Paddle(int x, int y, PaddleControl *pc);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

    private:
        float x;
        float y;
        float speed;
        PaddleControl* pc;

    protected:
        void advance(int step);
};


#endif
