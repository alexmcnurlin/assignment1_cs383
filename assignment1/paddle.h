#ifndef PADDLE_H
#define PADDLE_H
#include <QGraphicsItem>

class Paddle : public QGraphicsItem {
    public:
        Paddle();
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

    private:
        int x;
        int y;
        int speed;

    protected:
        void advance(int step);
};
#endif
