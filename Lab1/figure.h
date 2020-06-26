#ifndef FIGURE_H
#define FIGURE_H

#include "points.h"
#include "links.h"
#include "drawing.h"
#include "move.h"
#include "scale.h"
#include "turn.h"
#include "load_file.h"

struct figure
{
    points_data points;
    links_data links;
};

figure& init();
int free_figure(figure& fig);
int translate_figure(figure& fig, figure& tmp);
int load_figure_from_file(figure &fig, load_file file);

int draw_figure(figure& fig, draw arg);

int move_figure(figure& fig, move coeff);
int scale_figure(figure& fig, scale coeff);
int turn_figure(figure& fig, turn coeff);

#endif // FIGURE_H
