
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

void obogati(char** niz){
char* tempString = calloc(1001, sizeof(char));

char* start = "<h1>";
char* end = "</h1>";

strcpy(tempString, *niz);

    strcpy(*niz, start);
    strcat(*niz, tempString);
    strcat(*niz, end);
}

void vstaviH1(Vozlisce* zacetek) {

    Vozlisce* start = zacetek;
    Vozlisce* temp = zacetek;

    while (temp!=NULL){
        if (temp->niz[0]!='\0'){
            obogati( &(temp->niz) );
        }
        temp=temp->naslednje;
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
