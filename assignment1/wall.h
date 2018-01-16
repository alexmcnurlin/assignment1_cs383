#ifndef WALL_H
#define WALL_H
#include <QRectF>
#include <QPainter>
#include <QGraphicsItem>

class Wall : public QGraphicsItem {
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
