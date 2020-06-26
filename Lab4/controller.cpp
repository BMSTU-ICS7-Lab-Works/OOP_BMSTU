#include "controller.h"
#include <QDebug>

Controller::Controller()
{
    current_floor = 1;
    target_floor = NO_TARGET;
    state = FREE;
    //QObject::connect(this, SIGNAL(MoveFromTo(int, int)), &cabin, SLOT(slotProcessTarget(int, int)));
    QObject::connect(&cabin, SIGNAL(Default_condition(int)), this, SLOT(slotFree(int)));
};

void Controller::slotFree(int floor)
{
    state = FREE;
    current_floor = floor;
    target_floor = NO_TARGET;
};

void Controller::slotBusy(int target_floor)
{
    state = BUSY;
    if (current_floor != target_floor)
        cabin.ProcessTarget(current_floor, target_floor);
};
