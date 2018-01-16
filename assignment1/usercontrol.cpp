#include "usercontrol.h"
#include <QTime>
#include <QKeyEvent>

UserControl::UserControl(QWidget *parent) : QWidget(parent) {
    this->setFocus();
};

int UserControl::movePaddle(QPointF currentLocation) {
    return this->direction;
}


void UserControl::keyPressEvent(QKeyEvent *e) {
    switch (e->key()) {
        case Qt::Key_Down:
            this->direction = 1;
            break;
        case Qt::Key_Up:
            this->direction = -1;
            break;
    }
}


void UserControl::keyReleaseEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Down || e->key() == Qt::Key_Up) {
        this->direction = 0;
    }
}


void UserControl::advance(int step) {
    // I had a problem where clicking in the window removed keyboard focus
    // This is a dirty way to fix that
    this->setFocus();
}
