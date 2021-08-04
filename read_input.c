#include "saclib.h"
#include "smooth_stratification.h"

Word make_variables(Word r)
{
	char s[4] = "x0";
	Word Vs = NIL;

	printf("%d\n", r);
	for (Word i = r; i > 0; i--) {
		s[1] = '0' + i;
		Vs = COMP(LFS(s), Vs);
	}

	return Vs;
}

int read_input(Word *r_, Word *P_)
{
	Word r, P;
	/* Read in a single polynomial */
	IPREAD(&r, &P);
	if (r <= 0) {
		SWRITE("Error: input polynomial must be in at least one variable.\n");

		return 1;
	}

	IPWRITE(r, P, make_variables(r));

	*r_ = r;
	*P_ = P;
	return 0;
}

