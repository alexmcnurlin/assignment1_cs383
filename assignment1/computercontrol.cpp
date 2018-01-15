#include "computercontrol.h"
#include <QTime>

ComputerControl::ComputerControl() {};

int ComputerControl::movePaddle() {
    return (qrand() % 3) - 1;
}
