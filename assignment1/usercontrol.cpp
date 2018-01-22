#include "usercontrol.h"
#include <QTime>
#include <QKeyEvent>

UserControl::UserControl(QWidget *parent) : QWidget(parent) {
    direction = 0;
    setFocus();
};


int UserControl::movePaddle(QPointF currentLocation) {
    return direction;
}


void UserControl::keyPressEvent(QKeyEvent *e) {
    switch (e->key()) {
        case Qt::Key_Down:
            direction = 1;
            break;
        case Qt::Key_Up:
            direction = -1;
            break;
    }
}


void UserControl::keyReleaseEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Down || e->key() == Qt::Key_Up) {
        direction = 0;
    }
}


void UserControl::advance(int step) {}
