#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "cabin.h"
#define FLOOR_NUMBERS 9
#define NO_TARGET -1

class Controller: public QObject
{
    Q_OBJECT
    enum ControllerState
    {
        FREE,
        BUSY
    };

public:
    explicit Controller();
    ControllerState state;
public slots:
    void slotFree(int floor);
    void slotBusy(int target_floor);
signals:
    void MoveFromTo(int current_floor, int target_floor);
private:
    int current_floor;
    int target_floor;
    Cabin cabin;
};

#endif // CONTROLLER_H
