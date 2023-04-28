
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "naloga.h"

int vsota(int* zac, int* kon){
    int sum=0;
    for (int i=0;zac[i]<=*kon;i++){
        sum+=zac[i];
    }
    return sum;
}

void indeksInKazalec(int* t, int* indeks, int** kazalec) {

        if (*indeks==-1){
            int index=0;
            while (*kazalec != &t[index]){
                index++;
            }
            *indeks=index;
        }
        else{
            *kazalec=&t[*indeks];
        }

}

void frekvenceCrk(char* niz, int** frekvence) {
    
    int* tabela=calloc(26,sizeof(int));

    for (int i=0;niz[i]!='\0';i++){
        char c=tolower(niz[i]);
        tabela[c-'a']+=1;
    }

    *frekvence=&tabela[0];

}

#ifndef test

int main() {
    int tab[]={1,2,3,4,5};
    int* zac=&tab[0];
    int* kon=&tab[4];
    printf("%d",vsota(zac,kon));

    return 0;
}


#endif
