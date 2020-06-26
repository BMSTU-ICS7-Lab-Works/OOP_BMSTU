#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QTimer>

#define TIME_DOOR_CLOSE 1000
#define TIME_DOOR_OPEN 1000

class Doors: public QObject
{
    Q_OBJECT
    enum DoorsState
    {
        CLOSED,
        OPENING,
        OPENED,
        CLOSING
    };

public:
    explicit Doors();
    DoorsState state;
public slots:
    void slotOpened();
    void slotOpening();
    void slotClosed();
    void slotClosing();
signals:
    void Close_doors();
    void Open_doors();

    void Doors_closed();
    void Doors_opened();
private:
    QTimer timer_Open;
    QTimer timer_Close;
};

#endif // DOORS_H
