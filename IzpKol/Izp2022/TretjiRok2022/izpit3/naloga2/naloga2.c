
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

void enrichen (char** string){
        char* new = malloc (1100*sizeof(char));
        strcpy(new, *string);
        sprintf(*string, "<h1>%s</h1>", new);
}


void vstaviH1(Vozlisce* zacetek) {

    Vozlisce* current = zacetek;

    Vozlisce* previous = NULL;

    while (current!=NULL){
        if (previous==NULL){ // prvi element linked lista
            if (current->naslednje!=NULL){
                if (current->niz[0]!='\0' && current->naslednje->niz[0]=='\0'){
                    enrichen(&(current->niz));
                }
                previous=current;
            }
            else{
                if (current->niz[0]!='\0'){
                    enrichen(&(current->niz));
                }
                previous=current;
            }
        }

        if (current->naslednje!=NULL){ // ne-prvi in ne-zadnji element linked lista
            if (previous->niz[0]=='\0' && current->niz[0]!='\0' && current->naslednje->niz[0]=='\0'){
                enrichen(&(current->niz));
            }
            previous=current;
        }
        if (current->naslednje==NULL){ // zadnji element linked lista
            if (previous->niz[0]=='\0' && current->niz[0]!='\0'){
                enrichen(&(current->niz));
            }
            previous=current;
        }

        // previous=current;
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
