
/*
Ro"cno poganjanje testnih programov (npr. test01.c):

gcc -Dtest test01.c naloga2.c
./a.out

Samodejno testiranje:

export name=naloga2
make test

Testni primeri:

test01: primer iz besedila
test02..test04: celoten seznam tvori cikel (acikli"cni del je prazen)
test05..test10: splo"sni primeri

.c: testni program (prebere testne podatke, pokli"ce va"so funkcijo in izpi"se rezultat)
.dat: testni podatki
.out: pri"cakovani izhod
.res: izhod va"sega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================

int exists(Vozlisce* temp, Vozlisce** vozlisca){

    int obstaja = -1;
    int counter=0;
    while (vozlisca[counter] != NULL){
        if (vozlisca[counter]==temp){
            return counter;
        }
        counter++;
    }
    return obstaja;

}

int dolzinaCikla(Vozlisce* zacetek) {
    
    Vozlisce* temp = zacetek;
    Vozlisce** vozlisca = calloc(1001, sizeof(Vozlisce*));

    int st = 0;

    while (temp != NULL){
        if (exists(temp, vozlisca) == -1){
            vozlisca[st]=temp;
            temp=temp->naslednje;
            st++;
        }
        else{
            int startIndex = exists(temp, vozlisca);
            return st - startIndex;
        }
    }
    return st;
}


//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main() {
    // Tole dopolnite, "ce "zelite funkcijo preveriti s svojimi lastnimi
    // testnimi primeri.
    return 0;
}

#endif
