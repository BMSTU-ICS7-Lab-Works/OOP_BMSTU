#ifndef CONNECTION_H
#define CONNECTION_H
#include "points.h"
#include "point.h"
#include "link.h"

struct links_data
{
    int n;
    link *arr;
};

int init_links(links_data &links);
int links_alloc(links_data &connections, int len);
int links_free(links_data &connections);
int read_n_links(links_data &connections, FILE *f);
int process_links(links_data& connections, FILE* f);

#endif // CONNECTION_H
