#include "cstdio"
#include <cstdlib>
#include "points.h"
#include "point.h"
#include "figure.h"
#include "error_handler.h"
#include "io.h"

int init_points(points_data &pts)
{
    pts.n = 0;
    pts.arr = NULL;
    return NONE;
}

int points_alloc(points_data& pts, int len)
{
    if (len > 0)
    {
        pts.n = len;
        pts.arr = (point*) calloc(len, sizeof(point));
    }
    else
        return NO_DOTS;

    if (!pts.arr)
        return PTR_ALL_ERR;

    return NONE;
}


int points_free(points_data &pts)
{
    pts.n = 0;
    if (pts.arr)
        free(pts.arr);
    return NONE;
}

//points_data &pts instead of dots and n
int read_n_points(points_data &pts, FILE *f)
{
    int err = 0;
    for (int i = 0; i < pts.n && !err; i++)
    {
        if (read_point(pts.arr[i], f))
            err = FILE_FORMAT_ERR;
    }
    return err;
}


int process_points(points_data &pts, FILE *f)
{
    int n;
    int err = read_amount(&n, f);

    if (!err)
    {
        err = points_alloc(pts, n);
        if (!err)
        {
            if ((err = read_n_points(pts, f)) == FILE_FORMAT_ERR)
                points_free(pts);
        }
    }
    return err;
}
