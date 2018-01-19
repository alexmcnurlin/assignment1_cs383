#ifndef BALL_H
#define BALL_H
#include <QGraphicsObject>
#include "paddle.h"


class Ball : public QGraphicsObject {

    public:
        Ball(qreal x, qreal y);
        ~Ball() {};
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
        void reflect(QGraphicsItem *b);
        void reset_ball();

    private:
        qreal x;
        qreal y;
        float xVel;
        float yVel;
        float maxVel;

        
    protected:
        void advance(int step);
};


#endif
