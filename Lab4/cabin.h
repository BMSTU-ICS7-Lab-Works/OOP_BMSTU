#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include "doors.h"

#define TIME_MOVE 1000

class Cabin: public QObject
{
    Q_OBJECT
    enum CabinState
    {
        WAIT,
        MOVE,
        STOP
    };

public:
    explicit Cabin();
    CabinState state;
    void ProcessTarget(int current_floor, int target_floor);
public slots:
    void slotWait();
    void slotMove();
    void slotStop(); 
signals:
    void Moving(int);
    void Achieved();
    void Move();
    void Default_condition(int);
private:
    Doors doors;
    QTimer timer_Move;
    int current_floor;
    int target_floor;
};

#endif // CABIN_H
