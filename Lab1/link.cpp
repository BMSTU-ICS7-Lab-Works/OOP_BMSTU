#include "error_handler.h"
#include "link.h"

int read_link(link &joint, FILE* f)
{
    if (fscanf(f, "%d%d", &joint.p1, &joint.p2) != 2)
        return FILE_FORMAT_ERR;

    return NONE;
}
