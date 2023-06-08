
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

int indexExists(Vozlisce** seznam, Vozlisce* temp){

    int obstaja = -1;

    for (int i=0; seznam[i]!=NULL; i++){
        if (seznam[i] == temp){
            return i;
        }
    }
    return obstaja;

    
}


int dolzinaCikla(Vozlisce* zacetek) {
    
    Vozlisce* temp = zacetek;
    Vozlisce** seznam = calloc (1001, sizeof(Vozlisce*));

    int st = 0;
    while (temp!=NULL){
        int stevilka = indexExists(seznam, temp);
        if (stevilka == -1){
            seznam[st]=temp;
            st++;
        }
        else{
            return st-stevilka;
        }
        temp=temp->naslednje;
    }
    return 0;
    
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
