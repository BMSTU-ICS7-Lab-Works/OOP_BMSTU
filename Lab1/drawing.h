#ifndef DRAWING_H
#define DRAWING_H
#include "QGraphicsView"
#include "graph.h"
#include "points.h"
#include "links.h"

struct draw
{
    QGraphicsView *gV;
    int w;
    int h;
};

struct coord_point
{
    double x;
    double y;
};

coord_point get_dot(point* dots, int n);
coord_point point_transform(coord_point dot, draw arg);
int draw_links(points_data pts, links_data links, draw arg, graphics a);
int draw_line(coord_point p1, coord_point p2, graphics a, draw arg);
int my_addLine(graphics a, int x1, int x2, int y1, int y2);

#endif // DRAWING_H
