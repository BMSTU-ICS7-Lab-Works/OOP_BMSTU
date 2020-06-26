#include "error_handler.h"
#include "point.h"

int read_point(point& dot, FILE* f)
{
    if (fscanf(f, "%lf%lf%lf", &dot.x, &dot.y, &dot.z) != 3)
        return FILE_FORMAT_ERR;

    return NONE;
}
