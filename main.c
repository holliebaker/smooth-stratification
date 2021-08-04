#include <stdio.h>
#include "smooth_stratification.h"
#include "saclib.h"

int sacMain(int argc, const char **argv)
{
	/* Read data from stdin, robustly, continuing until read is successful. */
	Word r, P, t = 1;
	while (t != 0) {
		t = read_input(&r, &P);
	}

    return 0;
}

