#ifndef COMPC_H
#define COMPC_H

#include "paddlecontrol.h"
/* #include <QKeyEvent> */
/* #include <QWidget> */

class ComputerControl : public PaddleControl {
    public:
        ComputerControl();
        int movePaddle();
};

#endif
