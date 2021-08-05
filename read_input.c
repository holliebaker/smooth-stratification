#include "saclib.h"
#include "smooth_stratification.h"

int read_input(Word *r_, Word *V_, Word *P_)
{
    Word r, V, P, t;

	/* Read in variable list for the polynomial */
	SWRITE("Enter a variable list:\n");
	V = VLREAD();
	r = LENGTH(V);

	if (r < 1) {
		return 0;
	}

    /* Read in a single polynomial */
	SWRITE("Enter an integral polynomial in ");
	VLWRITE(V);
	SWRITE(" variables:\n");
    IPEXPREAD(r, V, &P, &t);
    if (t == 0) {
        SWRITE("Error: input polynomial must be in at least one variable.\n");

        return 0;
    }

    *r_ = r;
    *V_ = V;
    *P_ = P;
    return 1;
}

