#include <stdio.h>
#include "smooth_stratification.h"
#include "saclib.h"

int sacMain(int argc, const char **argv)
{
    /* Read data from stdin, robustly, continuing until read is successful. */
    Word r, P, V, t = 0;
    while (t != 1) {
        t = read_input(&r, &V, &P);
    }

    /* Write out the polynomial for testing purposes */
    LWRITE(P);
    SWRITE("\n");
    LWRITE(V);
    SWRITE("\n");
    IPWRITE(r, P, V); SWRITE("\n\n");

    return 0;
}

