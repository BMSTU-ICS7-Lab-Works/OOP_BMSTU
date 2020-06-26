#ifndef LINK_H
#define LINK_H

#include <cstdio>
//#include "links.h"

struct link
{
    int p1;
    int p2;
};

int read_link(link &joint, FILE* f);

#endif // LINK_H
