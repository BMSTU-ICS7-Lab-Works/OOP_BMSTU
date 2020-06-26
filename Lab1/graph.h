#ifndef GRAPH_H
#define GRAPH_H

#include "QGraphicsView"

struct graphics
{
    QGraphicsScene *scene;
    QPen pen;
};

int init_graph(graphics &a, QGraphicsView *gV);
int init_pen(graphics &a);
int del(graphics &a);
int set(QGraphicsView *gV, graphics &a);
int my_setScene(draw arg, graphics &a);

#endif // GRAPH_H
