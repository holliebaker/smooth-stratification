#ifndef __SMOOTH_STRATIFICATION__
#define __SMOOTH_STRATIFICATION__

#include "saclib.h"
#include "constants.h"

int read_input(Word *r, Word *V, Word *P);
void write_output(Word r, Word V, Word S);
void stratify(Word r, Word P, Word *Strata);

#endif
