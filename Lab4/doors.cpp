#include "doors.h"

#include <QDebug>

Doors::Doors()
{
    state = OPENED;
    QObject::connect(this, SIGNAL(Close_doors()), this, SLOT(slotClosing()));
    QObject::connect(this, SIGNAL(Open_doors()), this, SLOT(slotOpening()));

    QObject::connect(&timer_Open, SIGNAL(timeout()), this, SLOT(slotOpened()));
    QObject::connect(&timer_Close, SIGNAL(timeout()), this, SLOT(slotClosed()));
}

void Doors::slotClosed()
{
    if (state == CLOSING)
    {
        state = CLOSED;
        qDebug() << "Doors are closed";
        timer_Close.stop();
        emit Doors_closed();
    }
};

void Doors::slotClosing()
{
    if (state == OPENED)
    {
        state = CLOSING;
        qDebug() << "Doors are closing";
        timer_Close.start(TIME_DOOR_CLOSE);
    }
};

void Doors::slotOpened()
{
    if (state == OPENING)
    {
        state = OPENED;
        timer_Open.stop();
        qDebug() << "Doors are opened";
        emit Doors_opened();
    }
};

void Doors::slotOpening()
{
    if (state == CLOSED)
    {
        state = OPENING;
        qDebug() << "Doors are opening";
        timer_Open.start(TIME_DOOR_OPEN);
    }
    if (state == CLOSING)
    {
        state = OPENING;
        qDebug() << "Doors are opening";
        int t = timer_Close.remainingTime();
        timer_Close.stop();
        timer_Open.start(TIME_DOOR_OPEN - t);
    }
};
