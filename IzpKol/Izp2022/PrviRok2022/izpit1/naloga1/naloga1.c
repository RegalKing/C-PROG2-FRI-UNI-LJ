
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

    char* stevilka = calloc(10,sizeof(char));
    
    int sum = 0;

    for (int i=0; niz[i]!='\0'; i++){
        if (niz[i]=='E'){
            i++;
            if (isdigit(niz[i]) && niz[i]!='0'){
                stevilka[0]=niz[i];
                i++;
                if (isdigit(niz[i])){
                    stevilka[1]=niz[i];
                    i++;
                    if (isdigit(niz[i])){
                        stevilka[2]=niz[i];
                        stevilka[3]='\0';
                        i++;
                        if (niz[i]=='_'){
                            // printf("%d ", atoi(stevilka));
                            sum+=atoi(stevilka);
                            
                        }
                        else{
                            i--;
                        }
                    }
                    else{
                        i--;
                    }
                }
                else{
                    i--;
                }
            }
            else{
                i--;
            }
        }
    }
    return sum;




}

//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main() {
    // Tole dopolnite, "ce "zelite funkcijo testirati s svojimi lastnimi nizi.
    return 0;
}

#endif
