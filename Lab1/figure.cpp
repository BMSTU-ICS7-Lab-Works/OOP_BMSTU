#include "cstdio"
#include <cstdlib>
#include "figure.h"
#include "error_handler.h"
#include "points.h"
#include "links.h"
#include "drawing.h"
#include "graph.h"

figure& init()
{
    static figure fig;

    init_points(fig.points);

    init_links(fig.links);

    return fig;
}


int free_figure(figure& fig)
{
    points_free(fig.points);

    links_free(fig.links);
    return NONE;
}

int translate_figure(figure& fig, figure& tmp)
{
    fig.points.n = tmp.points.n;
    fig.points.arr = tmp.points.arr;

    fig.links.n = tmp.links.n;
    fig.links.arr = tmp.links.arr;
    return NONE;
}


int load_figure_from_file(figure& fig, load_file file)
{
    FILE *f = fopen(file.filename, "r");
    if (!f)
        return FILE_NOT_FOUND;
    figure fig_tmp = init();

    int err = process_points(fig_tmp.points, f);
    if (!err)
    {
        err = process_links(fig_tmp.links, f);
        if (err != NONE)
            points_free(fig_tmp.points);
    }
    fclose(f);
    if (!err)
    {
        free_figure(fig);
        translate_figure(fig, fig_tmp);
    }

    return err;
}

int draw_figure(figure& fig, draw arg)
{
    graphics a;

    int err = init_graph(a, arg.gV);  
    if (err)
        return err;
    init_pen(a);
    draw_links(fig.points, fig.links, arg, a);

    my_setScene(arg, a);
    set(arg.gV, a);

    return err;
}

int move_figure(figure& fig, move coeff)
{
    return move_points_array(fig.points.arr, fig.points.n, coeff);
}

int scale_figure(figure& fig, scale coeff)
{
    return scale_points_array(fig.points.arr, fig.points.n, coeff);
}

int turn_figure(figure& fig, turn coeff)
{
    return turn_points_array(fig.points.arr, fig.points.n, coeff);
}
