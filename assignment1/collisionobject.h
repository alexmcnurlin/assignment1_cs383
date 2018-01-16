#ifndef COLLO_H
#define COLLO_H
#include <QGraphicsItem>
#include "ball.h"


class CollisionObject : public QGraphicsItem {
    public:
        CollisionObject();
        virtual void reflect(Ball *b);
};


#endif
