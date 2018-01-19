#ifndef WALL_H
#define WALL_H
#include <QRectF>
#include <QPainter>
#include <QGraphicsObject>

class Wall : public QGraphicsObject {
    public:
        Wall(int x, int y, int w, int h);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

    private:
        int w;
        int h;
};

#endif
