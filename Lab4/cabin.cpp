#include "cabin.h"
#include "doors.h"
#include <QDebug>

Cabin::Cabin()
{
    state = WAIT;
    QObject::connect(&doors, SIGNAL(Doors_closed()), this, SLOT(slotMove()));
    QObject::connect(&doors, SIGNAL(Doors_opened()), this, SLOT(slotWait()));

    //QObject::connect(this, SIGNAL(Move()), this, SLOT(slotMove()));
    QObject::connect(&timer_Move, SIGNAL(timeout()), this, SLOT(slotMove()));
    QObject::connect(this, SIGNAL(Achieved()), this, SLOT(slotStop()));
};

void Cabin::slotWait()
{
    if (state == STOP)
    {
        state = WAIT;
        emit Default_condition(current_floor);
    }
}

void Cabin::ProcessTarget(int start_floor, int target_floor)
{
    if (state == WAIT)
    {
        current_floor = start_floor;
        this->target_floor = target_floor;
        emit doors.Close_doors();
    }
}

void Cabin::slotMove()
{
    if (state == WAIT)
    {
        state = MOVE;
        if (current_floor < target_floor)
            qDebug() << "edem-edem vverh";
        else
            qDebug() << "edem-edem vniz";
        timer_Move.start(TIME_MOVE);
    }
    if (state == MOVE)
    {
        current_floor < target_floor ? current_floor++ : current_floor--;
        if (current_floor == target_floor)
        {
            timer_Move.stop();
            qDebug() << "priehali";
            emit Achieved();
        }
        else
        {
            if (current_floor < target_floor)
                qDebug() << "edem-edem vverh";
            else
                qDebug() << "edem-edem vniz";
            timer_Move.start(TIME_MOVE);
        }
    }
};

void Cabin::slotStop()
{
    if (state == MOVE)
    {
        state = STOP;
        emit doors.Open_doors();
    }
};
