#ifndef MOVE_H
#define MOVE_H

#include "points.h"
#include "error_handler.h"

struct move
{
    int dx;
    int dy;
    int dz;
};

int move_points_array(point* pts, int n, move coeff);

#endif // MOVE_H
