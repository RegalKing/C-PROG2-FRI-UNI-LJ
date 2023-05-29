
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

void izlociSkupne(Vozlisce* a, Vozlisce* b, Vozlisce** noviA, Vozlisce** noviB) {
    
    Vozlisce* temp = a;
    Vozlisce* temp2 = NULL;

    int* grda = malloc (1001 * sizeof(int));
    grda[1001]=INT_MAX;

    int grdaCounter=-1;

    while (temp!=NULL){
        int st = temp->podatek;
        temp2=b;
        while (temp2!=NULL){
            if (st == temp2->podatek){
                grdaCounter++;
                grda[grdaCounter]=temp->podatek;
                temp->podatek=-1;
                break;
            }
            temp2=temp2->naslednje;
        }
        temp=temp->naslednje;
    }

    temp = b;
    temp2 = NULL;

    while (temp!=NULL){
        int st = temp->podatek;
        for (int i=0; i<=grdaCounter; i++){
            if(st==grda[i]){
                temp->podatek=-1;
            }
        }
        temp=temp->naslednje;
    }

    Vozlisce* zacetek = NULL;
    Vozlisce* previous = NULL;
    // Vozlisce* current = NULL;
    temp = b;

    while (temp!=NULL){
        int st = temp->podatek;
        if ( (st!= -1) && (zacetek==NULL) ){
            zacetek=temp;
            previous=temp;
        }
        else if (st!= -1){
            previous->naslednje=temp;
            previous=temp;
        }

        temp=temp->naslednje;
    }




    // Vozlisce* zacetek = NULL;
    // temp = a;
    // while(temp!=NULL){
    //     if (temp->podatek== -1){
    //         continue;
    //     }
    //     else if (temp->podatek== -1 && zacetek==NULL){
    //         zacetek=temp;
    //     }
        
    //     temp=temp->naslednje;
    // }

    // int zacetek=0;
    // Vozlisce* start = NULL;
    // temp = a;
    // while (temp!=NULL){
    //     if ( (temp->podatek)==-1 && zacetek==0){
    //         continue;
    //     }
    //     else if (zacetek==0 && temp->podatek!= -1){
    //         start=temp;
    //     }
    //     temp=temp->naslednje;
    // }

    *noviA=a;
    *noviB=zacetek;
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
