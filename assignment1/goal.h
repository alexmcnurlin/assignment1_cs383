#ifndef GOAL_H
#define GOAL_H
#include <QGraphicsObject>
#include <QRectF>
#include "ball.h"

class Goal : public QGraphicsObject {

    public:
        Goal(int x, int y, int w, int h, Ball *b);
        ~Goal() {};
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

    private:
        int x;
        int y;
        int w;
        int h;
        Ball *ball;
        int score;

    protected:
        void advance(int step);
};

#endif
