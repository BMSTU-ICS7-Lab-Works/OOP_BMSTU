#include <cstdlib>
#include "links.h"
#include "link.h"
#include "figure.h"
#include "error_handler.h"
#include "io.h"

int init_links(links_data &links)
{
    links.n = 0;
    links.arr = NULL;
    return NONE;
}

int links_alloc(links_data &connections, int len)
{
    if (len > 0)
    {
        connections.n = len;
        connections.arr = (link*) calloc(len, sizeof(link));
    }
    else
        return NO_LINKS;
    if (!connections.arr)
        return PTR_ALL_ERR;

    return NONE;
}


int links_free(links_data &connections)
{
    connections.n = 0;
    if (connections.arr)
        free(connections.arr);
    return NONE;
}


int read_n_links(links_data &connections, FILE *f)
{
    int err = 0;
    for (int i = 0; i < connections.n && !err; i++)
    {
        if (read_link(connections.arr[i], f))
            err = FILE_FORMAT_ERR;
    }

    return err;
}


int process_links(links_data& connections, FILE* f)
{
    int n;
    int err = 0;

    err = read_amount(&n, f);
    if (!err)
    {
        err = links_alloc(connections, n);

        if (!err)
        {
            if ((err = read_n_links(connections, f)) == FILE_FORMAT_ERR)
                links_free(connections);
        }
    }
    return err;
}
