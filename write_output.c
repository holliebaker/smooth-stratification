#include "saclib.h"
#include "smooth_stratification.h"

/*======================================================================
 * Write out computed strata
 * read_input(r, V, S)
 *      r: number of variables
 *      V: variable list, [x1,...,xr]
 *      S: list of lists of atomic formulas representing strata
 *
 *====================================================================*/


void write_op(Word op)
{
    switch (op) {
        case LTOP:
            SWRITE("<");
            break;
        case EQOP:
            SWRITE("=");
            break;
        case GTOP:
            SWRITE(">");
            break;
        case GEOP:
            SWRITE(">=");
            break;
        case NEOP:
            SWRITE("/=");
            break;
        case LEOP:
            SWRITE("<=");
            break;
        default:
            SWRITE("?");
    }
}

void write_output(Word r, Word V, Word S)
{
    Word i, S1, A, P, OP, a;

    i = 0;
    while (S != NIL) {
        ADV(S, &S1, &S);
        i++;

        SWRITE("X^"); IWRITE(i); SWRITE(" =\n");

        while(S1 != NIL) {
            ADV(S1, &A, &S1);

            SWRITE("    "); FIRST3(A, &P, &OP, &a);

            IPWRITE(r, P, V); SWRITE(" "); write_op(OP); SWRITE(" "); IWRITE(a); SWRITE("\n");
        }

        SWRITE("\n\n");
    }
}

