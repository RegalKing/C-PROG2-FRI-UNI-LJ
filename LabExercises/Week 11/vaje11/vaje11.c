
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int vsotaI(Vozlisce* zacetek) {
    
    int sum = 0;
    Vozlisce* temp = zacetek;
    while (temp != NULL){
        sum += temp->podatek;
        temp=temp->naslednje;
    }

    return sum;

}

int vsotaR(Vozlisce* zacetek) {
    
    if (zacetek==NULL){
        return 0;
    }
    else{
        return zacetek->podatek + vsotaR(zacetek->naslednje);
    }
}

Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element) {
    
    Vozlisce* current = zacetek;
    Vozlisce* previous = NULL;

    while (current != NULL && current->podatek < element){
        previous = current;
        current = current -> naslednje;
    }

    Vozlisce* new = malloc (sizeof(Vozlisce));
    new->podatek=element;
    new->naslednje=current;
    
    if (previous == NULL){
        return new;
    }
    else{
        previous->naslednje=new;
        return zacetek;
    }
}

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element) {

    if (zacetek==NULL){
        Vozlisce* new = malloc (sizeof(Vozlisce));
        new->podatek=element;
        new->naslednje=NULL;
        return new;
    }

    if (zacetek->podatek > element){
        Vozlisce* new = malloc (sizeof(Vozlisce));
        new->podatek=element;
        new->naslednje=zacetek;
        return new;
    }
    else{ 
        zacetek->naslednje = vstaviUrejenoR(zacetek->naslednje, element);
        return zacetek;
    }


}

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}
