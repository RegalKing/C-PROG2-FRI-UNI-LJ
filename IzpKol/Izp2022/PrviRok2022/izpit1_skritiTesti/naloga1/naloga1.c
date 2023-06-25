
/*
Ro"cno poganjanje testnih programov (npr. test01.c):

gcc -Dtest test01.c naloga1.c
./a.out

Samodejno testiranje:

export name=naloga1
make test

Testni primeri:

test01: primer iz besedila
test02..test08: ro"cno izdelani kratki testi
test09..test11: samodejno izdelani, tip Exxx_Exxx_Exxx_...
test12..test14: samodejno izdelani, vsakemu E-ju sledi "stevilo iz [100, 999]
test15..test17: samodejno izdelani, splo"sni

.c: testni program (prebere testne podatke, pokli"ce va"so funkcijo in izpi"se rezultat)
.dat: testni podatki
.out: pri"cakovani izhod
.res: izhod va"sega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "naloga1.h"

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================

int sestEj(char* niz) {

    char* temp = calloc(10,sizeof(char));

    int sum = 0;
    for (int i=0; niz[i]!='\0'; i++){
        if (niz[i]=='E' && (niz[i+1]!='0' && isdigit(niz[i+1])) && isdigit(niz[i+2]) && isdigit(niz[i+3]) && niz[i+4]=='_'){
            temp[0]=niz[i+1];
            temp[1]=niz[i+2];
            temp[2]=niz[i+3];
            temp[3]='\0';
            int currentNumber = atoi(temp);
            if (currentNumber>99){
                sum+=currentNumber;
            }

            i+=4;
        }
    }
    return sum;




}

//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main() {
    char* lol="543_E123_e456_E75_E900/E7.4_E825.3_E0357_E089_E_EE651_abcdE736_E842";
    int lol2 = sestEj(lol);
    return 0;
}

#endif
