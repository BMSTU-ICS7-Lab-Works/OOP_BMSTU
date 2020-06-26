#ifndef POINT_H
#define POINT_H

#include <cstdio>
//#include "points.h"

struct point
{
    double x;
    double y;
    double z;
};

int read_point(point& dot, FILE* f);

#endif // POINT_H
