#include "saclib.h"
#include "smooth_stratification.h"

/*======================================================================
 * Smooth stratification algorithm
 * stratify(r, P; S)
 *      r: number of variables
 *      P: integral polynomial in [x1,...,xr]
 *      S: a list [S1,...,Sk] of list of "atomic formulas" for smooth strata.
 *
 * "atomic formula" is a list [OP, P, 0] where P is a polynomial, OP is a relational operator,
 * so that we have P OP 0.
 *
 *====================================================================*/


void stratify(Word r, Word P, Word *Strata_)
{
    if (r == 1) {
        SWRITE("Nothing to do for R^1.\n");
        *Strata_ = NIL;

        return;
    }

    if (r > 2) {
        SWRITE("TODO: R^3 and above not implemented yet.\n");

            *Strata_ = NIL;
        return;
    }

    SWRITE("We assume that 0 is a regular value of P.\n");

    Word S, X1 = NIL, X2 = NIL;

    for (Word i = r; i > 0; i--) {
        Word D1 = IPDER(r, P, i);

        X1 = COMP(
            LIST3(D1, NEOP, 0),
            X1
        );

        X2 = COMP(
            LIST3(D1, EQOP, 0),
            X2
        );
    }

    S = LIST2(X1, X2);

    *Strata_ = S;
}

