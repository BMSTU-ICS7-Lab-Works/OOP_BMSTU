#ifndef SCALE_H
#define SCALE_H

#include "points.h"
#include "error_handler.h"

struct scale
{
    double kx;
    double ky;
    double kz;
};

int scale_points_array(point* pts, int n, scale coeff);

#endif // SCALE_H
