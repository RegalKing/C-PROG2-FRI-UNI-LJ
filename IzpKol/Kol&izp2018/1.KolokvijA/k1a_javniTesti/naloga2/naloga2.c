
/*
 * Va"sa re"sitev druge naloge --- datoteko dopolnite in jo oddajte na spletno u"cilnico!
 *
 * Your solution to task 1 --- complete the file and submit it to U"cilnica!
 *
 * V naslednjo vrstico vpi"site va"so vpisno "stevilko / Enter your student ID number in the next line:
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "naloga2.h"

/*
 * Testni primeri J1--J2 in S1--S10 testirajo rezultat funkcije.
 * Testni primeri J3--J4 in S11--S20 testirajo vrednost spremenljivke, na
 *     katero ka"ze kazalec <indeks>.
 *
 * Test cases J1--J2 and S1--S10 check the result of the function.
 * Test cases J3--J4 and S11--S20 check the value of the variable pointed to
 *     by <indeks>.
 */
int steviloInKta(char* niz, int k, int* indeks) {

    int capCounter=0;
    int kfound=0;

    for (int i=0;niz[i]!='\0';i++){
        if (isupper(niz[i])){
            capCounter++;
        }
        if (capCounter==k && kfound==0){
            kfound=1;
            *indeks=i;
            
        }
    if (capCounter<k){
        *indeks=-1;
    }
    }

    return capCounter;
}

void indeksi(char* niz, int** t) {
    // v t tabelo z padajocimi indeksi velikih crk v nizu
    int capCount=0;

    for (int i=0;niz[i]!='\0';i++){
        if (isupper(niz[i])){
            capCount++;
        }
    }

    int* capList=calloc(capCount,sizeof(int));
    int capCount2=-1;
    for (int i=0;niz[i]!='\0';i++){
        if (isupper(niz[i])){
            capCount2++;
            capList[capCount2]=i;
            //printf("%d\n",capList[capCount2]);
        }
    }
    int* capList2=calloc(capCount+1,sizeof(int));
    //printf("Capitalized letter count:%d",capCount);

    int counterIndexaCapLista=capCount2;
    for (int i=0;i<=capCount2;i++){
        capList2[i]=capList[counterIndexaCapLista];
        counterIndexaCapLista--;
    }

    capList2[capCount2+1]=-1;
    *t=&(capList2[0]);


}

char** zadnje(char** nizi) {
    int StNizov=0;
    for (int i=0;nizi[i]!=NULL;i++){
        StNizov++;
    }

    char** tabela=calloc(StNizov+1,sizeof(char*));
    for (int i=0;nizi[i]!=NULL;i++){
        char* zadnjaVelika=NULL;
        for (int j=0;((nizi[i])[j])!='\0';j++){
            if (isupper((nizi[i])[j])){
                zadnjaVelika=&((nizi[i])[j]);
            }
        }
        tabela[i]=zadnjaVelika;
    }
    return tabela;
}

int main() {


    return 0;
}
