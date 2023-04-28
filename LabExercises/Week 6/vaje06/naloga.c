
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int steviloZnakov(char* niz, char znak) {
    int sum=0;

    for (int i=0;niz[i]!='\0';i++){
        if (niz[i]==znak){
            sum++;
        }
    }
    return sum;
}

char* kopirajDoZnaka(char* niz, char znak) {
    
    int length=0;
    while (niz[length]!=znak && niz[length]!='\0'){
        length++;
    }
    

    char* new=calloc(length+1,sizeof(char));

    for (int i=0;i<length;i++){
        new[i]=niz[i];
    }

    return new;
}

char** razcleni(char* besedilo, char locilo, int* stOdsekov) {
    int stLocil=steviloZnakov(besedilo,locilo);
    *stOdsekov=stLocil+1;
    char** odseki=calloc(*stOdsekov,sizeof(char*));

    int index=0;
    int start=0;

    for (int i=0;besedilo[i]!='\0';i++) {
        if (besedilo[i]==locilo){
            odseki[index]=kopirajDoZnaka(besedilo+start,locilo);
            start=i+1;
            index++;
        }
    }
    odseki[index]=kopirajDoZnaka(besedilo+start,'\0');

    return odseki;
}


#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
