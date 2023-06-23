
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -D=test testXY.c naloga3.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Testni primeri:
 * 02, 03: h = 1
 * 04, 05, 06: mesto = 0
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

// po potrebi dopolnite ...

Vozlisce* vstaviStolpec(Vozlisce* start, int mesto, int vsebina) {
    
    Vozlisce* temp = start;

    int stevec = 0;
    while (temp!=NULL){
        stevec++;
        temp=temp->desno;
    }
    temp=start;

    Vozlisce* first=temp;
    Vozlisce* last=temp;

    for (int i=0; i<mesto-1; i++){
        first=first->desno;
    }


    // return first;

    for (int i=0; i<mesto; i++){
        last=last->desno;
    }

    // return last;

if (mesto==0){
    first=start;
    Vozlisce* prior = NULL;
    int counter = vsebina;

    for (int i=0; first!=NULL; i++){
        if (i==0){
            Vozlisce* new = malloc(1*sizeof(Vozlisce));
            new->vsebina=counter;
            counter++;
            new->desno=first;
            new->dol=NULL;

            start = new;
            prior = new;
        }
        else{
            Vozlisce* new = malloc(1*sizeof(Vozlisce));
            new->vsebina=counter;
            counter++;
            new->desno=first;
            new->dol=NULL;

            prior->dol=new;
            prior=new;
        }
        first=first->dol;
    }

}

else{
    Vozlisce* priorNew=NULL;

    int counter = vsebina;
    for (int i=0; first!=NULL; i++){
        if (i==0){
            Vozlisce* new = malloc(1*sizeof(Vozlisce));
            new->vsebina=counter;
            counter++;
            new->desno=last;
            new->dol=NULL;

            first->desno=new;

            priorNew=new;
        }
        else{
            Vozlisce* new = malloc(1*sizeof(Vozlisce));
            new->vsebina=counter;
            counter++;
            new->desno=last;
            new->dol=NULL;

            priorNew->dol=new;

            first->desno=new;

            priorNew=new;

        }
            

        first=first->dol;
        last=last->dol;
    }
}
            
    return start;




}

//=============================================================================

#ifndef test

int main() {
    // "Ce "zelite funkcijo <vstaviStolpec> testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga3.c).
    return 0;
}

#endif
