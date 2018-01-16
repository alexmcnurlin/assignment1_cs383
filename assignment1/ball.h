#ifndef BALL_H
#define BALL_H
#include <QGraphicsItem>
#include "paddle.h"
/* #include "collisionobject.h" */


class Ball : public QGraphicsItem {
    public:
        Ball(qreal x, qreal y);
        ~Ball();
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
        void reflect(QGraphicsItem *b);

    private:
        qreal x;
        qreal y;
        float xVel;
        float yVel;
        
    protected:
        void advance(int step);
};


#endif
