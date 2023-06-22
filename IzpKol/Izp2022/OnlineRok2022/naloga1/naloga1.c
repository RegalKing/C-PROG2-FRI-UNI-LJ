
/*
Ro"cno poganjanje testnih programov (npr. test01.c):

gcc -Dtest test01.c naloga1.c
./a.out

Samodejno testiranje:

export name=naloga1
make test

Testni primeri:

test01..test03: ro"cno izdelani kratki testi
test04: samodejno izdelani, predpona = +386, dol"zina tel. "st. = 8
test05: samodejno izdelani, predpona = +386
test06..test10: samodejno izdelani, splo"sni

.c: testni program (prebere testne podatke, pokli"ce va"so funkcijo in izpi"se rezultat)
.dat: testni podatki
.out: pri"cakovani izhod
.res: izhod va"sega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================

void vstaviPredpono(char* predpona, Oseba** osebe, int stOseb) {
    
    for (int i=0; i<stOseb; i++){
        char* temp = malloc (33*sizeof(char));
        strcpy(temp, osebe[i]->telefon);
        strcpy(osebe[i]->telefon, predpona);
        strcat(osebe[i]->telefon, temp);
    }









}

//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main() {
    return 0;
}

#endif
