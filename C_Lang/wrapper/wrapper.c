#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "wrapper.h"

#define USE_VERSION 2

#if USE_VERSION == 1
/* Version 1 */
struct context_t
{
    const char *name;
    int size;
    FILE *fd;
};

struct context_t * My_Open(const char *name)
{
    struct context_t *c = (struct context_t *)malloc(sizeof(struct context_t));
    bzero(c, sizeof(struct context_t));

    c->name = strdup(name);
    c->size = 0;
    c->fd = fopen(name, "r");

    return c;
}

int is_success(struct context_t *c)
{
    return c->fd == NULL ? 0 : 1;
}
/* Version 1 Ends */
#endif


#if USE_VERSION == 2
/* Version 2 */

/* Someday, I plan to change how My_Open works */
struct context_t
{
    const char *name;
    int fd;                     /* Use low-level file descriptor */
};

struct context_t * My_Open(const char *name)
{
    struct context_t *c = (struct context_t *)malloc(sizeof(struct context_t));
    bzero(c, sizeof(struct context_t));

    c->name = strdup(name);
    c->fd = open(name, O_RDONLY);

    return c;
}

int is_success(struct context_t *c)
{
    return c->fd == -1 ? 0 : 1;
}

#endif
