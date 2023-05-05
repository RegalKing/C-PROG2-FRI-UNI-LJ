
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
 *
 * Javni testni primeri (po te"zavnosti):
 * -- 02, 03, 04: en sam vhodni niz;
 * -- 05, 06, 07: vsi vhodni nizi so enako dolgi;
 * -- 01, 08, 09, 10: splo"sni primeri.
 *
 * Javni testni primeri (po na"cinu priprave):
 * -- 01: primer iz besedila;
 * -- 01, 02, 05: ro"cno ustvarjeni;
 * -- ostali: samodejno generirani.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// po potrebi dopolnite ...

//=============================================================================

char** poStolpcih(char** nizi, int stVhodnih, int* stIzhodnih) {
    
    int maxLen=-1;
    for (int i=0;i<stVhodnih;i++){
        int length=strlen(nizi[i]);
        if (length>maxLen){
            maxLen=length;
        }
    }

    *stIzhodnih=maxLen;

    char** tabela=calloc(maxLen+1,sizeof(char*));
    for (int i=0;i<maxLen+1;i++){
        tabela[i]=calloc(stVhodnih+1,sizeof(char));
    }

    for (int i=0;i<maxLen;i++){
        int counter=0;
        for (int j=0;j<stVhodnih;j++){
            if (strlen(nizi[j])>i){
                tabela[i][counter]=nizi[j][i];
                counter++;
            }
        }
    }

    return tabela;
}

//=============================================================================

#ifndef test

char* NIZI[] = {
    "Danes",
    "je",
    "kolokvij",
    "pri_P2!",
};

int main() {
    int stIzhodnih = 0;
    char** rezultat = poStolpcih(NIZI, sizeof(NIZI) / sizeof(NIZI[0]), &stIzhodnih);
    printf("%d\n", stIzhodnih);

    for (int i = 0; i < stIzhodnih; i++) {
        printf("%s\n", rezultat[i]);
        free(rezultat[i]);
    }
    free(rezultat);

    return 0;
}

#endif
