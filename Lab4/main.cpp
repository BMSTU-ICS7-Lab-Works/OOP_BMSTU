#include "mainwindow.h"
#include "controller.h"

#include <QApplication>
#include <QDebug>
#include <QTimer>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller elevator;
    elevator.slotBusy(3);
    /*
    while (true)
    {
        qDebug() << "Enter floor to visit(0 to exec):";
        std::cin >> choice;
        qDebug() << "UEE BOI";
        if (choice >= 0 && choice <= 9)
            elevator.slotBusy(choice);
        else
            return a.exec();
    }
    */
    return a.exec();

}
