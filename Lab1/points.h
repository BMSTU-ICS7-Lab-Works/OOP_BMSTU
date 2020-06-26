#ifndef POINTS_H
#define POINTS_H

#include <cstdio>
#include "point.h"

struct points_data
{
    int n;
    point* arr;
};

int init_points(points_data &pts);
int points_alloc(points_data& pts, int len);
int points_free(points_data& pts);

int read_n_points(points_data &pts, FILE *f);
int process_points(points_data &pts, FILE *f);

#endif // POINT_H
