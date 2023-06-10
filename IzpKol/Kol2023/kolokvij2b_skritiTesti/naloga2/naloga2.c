
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

int exists(Vozlisce** seznam, Vozlisce* node){

    for (int i=0; seznam[i]!=NULL; i++){
        if (*(node->p)==*(seznam[i]->p)){
            return 1;
        }
    }
    return 0; // else
}


void izlociDuplikate(Vozlisce* zacetek) {

    // int* stevila = malloc (1000*sizeof(int));
    Vozlisce** seznam = calloc (1001,sizeof(Vozlisce*));

    Vozlisce* temp = zacetek;

    int index = -1;

    while (temp!=NULL){
        int exist = exists(seznam, temp);
        if (exist == 1){
        }
        else{
            index++;
            seznam[index]=temp;
        }
        temp=temp->naslednje;
    }

    for (int i=0; seznam[i]!=NULL; i++){
        Vozlisce* current = seznam[i];

        current->naslednje=seznam[i+1];
    }

    zacetek=seznam[0];




}

//=============================================================================

#ifndef test

int main() {
    

    return 0;
}

#endif
