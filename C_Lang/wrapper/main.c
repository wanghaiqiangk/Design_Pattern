#include <stdio.h>
#include <stdlib.h>
#include "wrapper.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }
    const char *name = argv[1];
    struct context_t *c = My_Open(name);
    if (is_success(c))
    {
        fprintf(stdout, "File open succeeds.\n");
    }
    else
    {
        fprintf(stderr, "File open fails.\n");
    }

    return 0;
}
