#include "usercontrol.h"
#include <QTime>
#include <QKeyEvent>

UserControl::UserControl(QWidget *parent) : QWidget(parent) {
    this->setFocus();
};

int UserControl::movePaddle() {
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
