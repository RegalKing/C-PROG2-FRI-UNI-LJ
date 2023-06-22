
/*
Ro"cno poganjanje testnih programov (npr. test01.c):

gcc -Dtest test01.c naloga2.c
./a.out

Samodejno testiranje:

export name=naloga2
make test

Testni primeri:

test01: primer iz besedila
test02..test08: ro"cno izdelani kratki testi
test09..test10: samodejno izdelani, zadnji element prvega seznama < prvi element drugega seznama
test11..test16: samodejno izdelani, splo"sni

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

Vozlisce* zlij(Vozlisce* a, Vozlisce* b) { // lepa resitev za 16/16 testnih , grsa ki je passala 12.5/16 je bila da sem naredil seznam vozlisc ampak tale je lepsa pa hitrejsa

Vozlisce new;
Vozlisce* newP = &new;

    while (a!=NULL || b!=NULL){
        if (a==NULL){
            newP->naslednje=b;
            b=b->naslednje;
            newP=newP->naslednje;
            newP->naslednje=NULL;
        }
        else if (b==NULL){
            newP->naslednje=a;
            a=a->naslednje;
            newP=newP->naslednje;
            newP->naslednje=NULL;
        }
        else if (a->podatek < b->podatek){
            newP->naslednje=a;
            a=a->naslednje;
            newP=newP->naslednje;
            newP->naslednje=NULL;
        }
        else if (b->podatek < a->podatek){
            newP->naslednje=b;
            b=b->naslednje;
            newP=newP->naslednje;
            newP->naslednje=NULL;
        }
    }
    newP=&new;
    return newP->naslednje;




}

//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main() {
    return 0;
}

#endif
