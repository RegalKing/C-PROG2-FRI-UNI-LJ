
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

#include "naloga2.h"

// po potrebi dopolnite ...

int exists (int* seznam, int podatek, int counter){

    for (int i=0; i<counter; i++){
        if (seznam[i]==podatek){
            return 1;
        }
    }
    return 0;
}

void izlociDuplikate(Vozlisce* zacetek) {

    Vozlisce** list = calloc(1001, sizeof(Vozlisce*));

    int* seznam = malloc(1000*sizeof(int));

    Vozlisce* temp = zacetek;

    int counter = 0;
    while (temp!=NULL){
        int obstaja = exists(seznam, *(temp->p), counter);
        if (obstaja==1){
        }
        else{
            seznam[counter]=*(temp->p);
            list[counter]=temp;
            counter++;
            
        }
        temp=temp->naslednje;
    }

    for (int i=0; i<counter; i++){
        list[i]->naslednje=list[i+1];
    }



}

//=============================================================================

#ifndef test

int main() {
    

    return 0;
}

#endif
