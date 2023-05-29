
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -D=test testXY.c naloga2.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#include "naloga2.h"

// po potrebi dopolnite ...

void izlociSkupne(Vozlisce* a, Vozlisce* b, Vozlisce** noviA, Vozlisce** noviB) {
    Vozlisce *currentA = a, *previousA = NULL;
    Vozlisce *currentB = b, *previousB = NULL;
    Vozlisce *tempA, *tempB;

    while (currentA != NULL) {
        currentB = b;
        previousB = NULL;
        while (currentB != NULL && currentB->podatek != currentA->podatek) {
            previousB = currentB;
            currentB = currentB->naslednje;
        }
        if (currentB != NULL) { // An element that both nodes have in common has beeen found
            if (previousA == NULL) {
                a = currentA->naslednje;
            } 
            else {
                previousA->naslednje = currentA->naslednje;
            }
            if (previousB == NULL) {
                b = currentB->naslednje;
            } 
            else {
                previousB->naslednje = currentB->naslednje;
            }
            tempA = currentA;
            tempB = currentB;
            currentA = currentA->naslednje;
            free(tempA);
            free(tempB);
        } 
        else { // No element in common, moving on to the next element in linked list A
            previousA = currentA;
            currentA = currentA->naslednje;
        }
    }
    *noviA = a;
    *noviB = b;
}









//=============================================================================

#ifndef test

int main() {
    // "Ce "zelite funkcijo izlociSkupne testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga2.c).
    return 0;
}

#endif
