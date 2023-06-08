
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

#include "naloga2.h"

// po potrebi dopolnite ...

void izlociDuplikate(Vozlisce* zacetek) {
    
    Vozlisce* start = zacetek;
    Vozlisce* temp = zacetek;

    int* numbers = malloc(1000 * sizeof(int));
    int numbersCount = 0;

    while (temp!=NULL){
        numbers[numbersCount]=*(temp->p);
        numbersCount++;
        temp=temp->naslednje;
    }

    temp = start;
    while (temp!=NULL){
        int currentNumber = *(temp->p);
        





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
