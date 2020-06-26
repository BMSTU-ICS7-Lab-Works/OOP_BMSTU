#include "turn.h"

int x_turn_point(double &y, double &z, double cy, double cz, double ox)
{
    double temp_y;
    temp_y = cy + (y - cy) * cos(ox * M_PI / 180) + (z - cz) * sin(ox * M_PI / 180);
    z = cz - (y - cy) * sin(ox * M_PI / 180) + (z - cz) * cos(ox * M_PI / 180);
    y = temp_y;
    return NONE;
}

int y_turn_point(double &x, double &z, double cx, double cz, double oy)
{

    double temp_x;
    temp_x = cx + (x - cx) * cos(oy * M_PI / 180) + (z - cz) * sin(oy * M_PI / 180);
    z = cz - (x - cx) * sin(oy * M_PI / 180) + (z - cz) * cos(oy * M_PI / 180);
    x = temp_x;
    return NONE;
}

int z_turn_point(double &x, double &y, double cx, double cy, double oz)
{
    double temp_x;
    temp_x = cx + (x - cx) * cos(oz * M_PI / 180) + (y - cy) * sin(oz * M_PI / 180);
    y = cy - (x - cx) * sin(oz * M_PI / 180) + (y - cy) * cos(oz * M_PI / 180);
    x = temp_x;
    return NONE;
}

int turn_point(point &pts, turn coeff)
{
    if (coeff.ox)
        x_turn_point(pts.y, pts.z, coeff.cy, coeff.cz, coeff.ox);
    if (coeff.oy)
        y_turn_point(pts.x, pts.z, coeff.cx, coeff.cz, coeff.oy);
    if (coeff.oz)
        z_turn_point(pts.x, pts.y, coeff.cx, coeff.cy, coeff.oz);
    return NONE;
}


int turn_points_array(point* pts, int n, turn coeff)
{
    if(!pts)
        return NO_DOTS;
    int err = 0;

    for(int i = 0; i < n; i++)
    {
        turn_point(pts[i], coeff);
    }

    return err;
}
