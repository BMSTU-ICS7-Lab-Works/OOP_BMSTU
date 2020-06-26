#include "graph.h"
#include "drawing.h"
#include "error_handler.h"

int init_graph(graphics &a, QGraphicsView *gV)
{
    a.scene = new QGraphicsScene(gV);
    if (!a.scene)
        return PTR_ALL_ERR;

    //a.pen = QPen(Qt::black);

    return NONE;;
}

int init_pen(graphics &a)
{
    a.pen = QPen(Qt::black);
    return NONE;
}

int del(graphics &a)
{
    delete a.scene;
    return NONE;
}

int set(QGraphicsView *gV, graphics &a)
{
    QGraphicsScene *prev = gV->scene();
    delete prev;
    gV->setScene(a.scene);
    return NONE;
}

int my_setScene(draw arg, graphics &a)
{
    a.scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(arg.w, arg.h)));
}
