
/*
Ro"cno poganjanje testnih programov (npr. test01.c):

gcc -Dtest test01.c naloga2.c
./a.out

Samodejno testiranje:

export name=naloga2
make test

Testni primeri:

01: primer iz besedila
02..04: ena sama vrstica
05..06: vsaka neprazna vrstica je naslovna
07..10: splo"sni primeri

Datoteke:

test*.c: testni program (prebere testne podatke, pokli"ce va"so funkcijo in izpi"se rezultat)
test*.dat: testni podatki
test*.out: pri"cakovani izhod testnega programa
test*.res: dejanski izhod testnega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================

void surround(char** zacetek){
    int length = strlen(*zacetek);
    char* temp = malloc((length+10)*sizeof(char));
    strcpy(temp,"<h1>");
    strcat(temp, *zacetek);
    strcat(temp,"</h1>");
    *zacetek=temp;
}


void vstaviH1(Vozlisce* zacetek) {

    Vozlisce* current = zacetek;
    Vozlisce* previous = NULL;

    while (current->naslednje != NULL){
        if ( (previous==NULL || previous->niz==NULL) && (current->niz!=NULL) ){
            surround(&(current->niz));
        }
        previous=current;
        current=current->naslednje;
    }
                
}

//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main() {
    // char* word="banana";
    // surround(&word);
    // printf("%s",word);
    // return 0;
}

#endif
