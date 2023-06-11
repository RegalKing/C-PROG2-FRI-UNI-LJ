
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -D=test testXY.c naloga2.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#include "naloga2.h"

// po potrebi dopolnite ...

int exists (int* stevilke, int podatek){

    for (int i=0; stevilke[i]!=INT_MIN; i++){
        if (stevilke[i]==podatek){
            return 1;
        }
    }
    return 0;
}

void izlociSkupne(Vozlisce* a, Vozlisce* b, Vozlisce** noviA, Vozlisce** noviB) {
    
    int* numbersA = malloc (1001 * sizeof(int));
    int* numbersB = malloc (1001 * sizeof(int));

    Vozlisce* temp = a;
    int counterA = 0;

    while (temp!=NULL){
        numbersA[counterA]=temp->podatek;
        temp=temp->naslednje;
        counterA++;
    }

    temp = b;
    int counterB = 0;

    while (temp!=NULL){
        numbersB[counterB]=temp->podatek;
        temp=temp->naslednje;
        counterB++;
    }

    numbersA[counterA]=INT_MIN;
    numbersB[counterB]=INT_MIN;

    temp = a; // zdej bomo A obdelal

    while (temp!=NULL){
        int stevilka = temp->podatek;   
        int obstaja = exists(numbersB, stevilka);
        if (obstaja == 1){
            temp->podatek=-1;
        }
        temp=temp->naslednje;
    }

    temp = b; // zdej bomo A obdelal

    while (temp!=NULL){
        int stevilka = temp->podatek;   
        int obstaja = exists(numbersA, stevilka);
        if (obstaja == 1){
            temp->podatek=-1;
        }
        temp=temp->naslednje;
    }

    temp = a;
    Vozlisce** vozlisca = malloc (1000*sizeof(Vozlisce*));

    int stevec = 0;
    while (temp!=NULL){
        if (temp->podatek == -1){
        }
        else{
            vozlisca[stevec]=temp;
            stevec++;
        }
        temp=temp->naslednje;
    }

    vozlisca[stevec+1]=NULL;

    for (int i=0; i<stevec; i++){
        vozlisca[i]->naslednje=vozlisca[i+1];
    }

    temp = b;
    Vozlisce** vozliscaB = malloc (1000*sizeof(Vozlisce*));

    stevec = 0;
    while (temp!=NULL){
        if (temp->podatek == -1){
        }
        else{
            vozliscaB[stevec]=temp;
            stevec++;
        }
        temp=temp->naslednje;
    }

    vozliscaB[stevec+1]=NULL;

    for (int i=0; i<stevec; i++){
        vozliscaB[i]->naslednje=vozliscaB[i+1];
    }


    *noviA=vozlisca[0];
    *noviB=vozliscaB[0];



}














//=============================================================================

#ifndef test

int main() {
    // "Ce "zelite funkcijo izlociSkupne testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga2.c).
    return 0;
}

#endif
