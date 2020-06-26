#ifndef TURN_H
#define TURN_H

#include "points.h"
#include "error_handler.h"
#include <math.h>

struct turn
{
    double ox;
    double oy;
    double oz;
    double cx;
    double cy;
    double cz;
};

int turn_points_array(point* pts, int n, turn coeff);

#endif // TURN_H
