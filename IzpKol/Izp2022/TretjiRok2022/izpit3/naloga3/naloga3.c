
/*
Ro"cno poganjanje testnih programov (npr. test01.c):

gcc -Dtest test01.c naloga3.c
./a.out

Samodejno testiranje:

export name=naloga3
make test

Testni primeri:

01: primer iz besedila
02..05: vsi elementi tabele so med seboj enaki
06..10: splo"sni primeri

Testne datoteke:

test*.c: testni program (prebere testne podatke, pokli"ce va"so funkcijo in izpi"se rezultat)
test*.dat: testni podatki
test*.out: pri"cakovani izhod testnega programa
test*.res: dejanski izhod testnega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================

Vozlisce* drevo(int n, int* podatki) {
    // popravite / dopolnite ...
    return NULL;
}

//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main() {
    // Tole dopolnite, "ce "zelite funkcijo lastnoro"cno preveriti.
    // V tem primeru program po"zenite preprosto kot
    // gcc naloga3.c
    // ./a.out
    return 0;
}

#endif
