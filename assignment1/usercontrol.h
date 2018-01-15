#ifndef USERC_H
#define USERC_H

#include "paddlecontrol.h"
#include <QKeyEvent>
#include <QWidget>

class UserControl : public PaddleControl, QWidget {
    public:
        UserControl(QWidget *parent);
        int movePaddle();

    private:
        int direction;

    protected:
        void keyPressEvent(QKeyEvent *e);
        void keyReleaseEvent(QKeyEvent *e);
};

#endif
