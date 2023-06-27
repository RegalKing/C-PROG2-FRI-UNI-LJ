
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
 * 04, 05, 06: preverjajo samo vsoto
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

// po potrebi dopolnite ...

Vozlisce* diagonala(Vozlisce* start, int* vsota) {
        Vozlisce* zacetek=start;
        Vozlisce* temp = start;

        int dolzina=0;
        int visina=0;

        while(temp!=NULL){
            dolzina++;
            temp=temp->desno;
        }
        temp=start;
        while (temp!=NULL){
            temp=temp->dol;
            visina++;
        }

        temp=start;

        Vozlisce** seznam = malloc(200*sizeof(Vozlisce*));
        int stevec = 0;
        while (temp!=NULL){
            seznam[stevec]=temp;
            // printf("[%d.%d] ", temp->vsebina,stevec);
            stevec++;
            temp=temp->desno;
        }

        // printf("%d ",stevec);

        int* stevilke=malloc(200*sizeof(int));
        int stCount=0;

        int premik=0;
        while (stevec>0 && visina>0){
            temp=seznam[stevec-1];
            int move = premik;
            while(move!=0){
                if (temp->dol!=NULL){
                    temp=temp->dol;
                    move--;
                }
                else{
                    move--;
                }
            }
            int current = temp->vsebina;
            stevilke[stCount]=current;
            stCount++;
            stevec--;
            premik++;
            visina--;
        }

        int sum=0;
        for (int i=0;i<stCount; i++){
            // printf("%d ",stevilke[i]);
            sum+=stevilke[i];
        }

        *vsota=sum;

        Vozlisce* newstart=malloc(sizeof(Vozlisce));
        Vozlisce* prev=malloc(sizeof(Vozlisce));
        for (int i=0; i<stCount; i++){
            if (i==0){
                newstart->dol=NULL;
                newstart->desno=NULL;
                newstart->vsebina=stevilke[i];
                prev=newstart;
            }
            else{
                Vozlisce* novo = malloc(sizeof(Vozlisce));
                novo->desno=NULL;
                novo->dol=NULL;
                novo->vsebina=stevilke[i];
                prev->desno=novo;
                prev=novo;
            }
        }




        
        
        start=zacetek;
        return newstart;

        
}

//=============================================================================

#ifndef test

#define _VISINA 3
#define _SIRINA 4

Vozlisce* _MATRIKA[_VISINA][_SIRINA];

const int _VSEBINA[_VISINA][_SIRINA] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
};

void _napolni() {
    for (int i = 0; i < _VISINA; i++) {
        for (int j = 0; j < _SIRINA; j++) {
            _MATRIKA[i][j] = calloc(1, sizeof(Vozlisce));
            _MATRIKA[i][j]->vsebina = _VSEBINA[i][j];
        }
    }
    for (int i = 0; i < _VISINA; i++) {
        for (int j = 0; j < _SIRINA; j++) {
            if (j < _SIRINA - 1) {
                _MATRIKA[i][j]->desno = _MATRIKA[i][j + 1];
            }
            if (i < _VISINA - 1) {
                _MATRIKA[i][j]->dol = _MATRIKA[i + 1][j];
            }
        }
    }
}

void _izpisiDiagonalo(Vozlisce* v) {
    printf("Diagonala:\n");
    printf("[");
    Vozlisce* w = v;
    while (w != NULL) {
        if (w != v) {
            printf(", ");
        }
        printf("%d", w->vsebina);
        w = w->desno;
    }
    printf("]\n\n");
}

void _izpisiOriginal(Vozlisce* v0) {
    printf("Originalna matrika -- po vrsticah:\n");
    Vozlisce* v = v0;
    int i = 0;
    while (v != NULL) {
        printf("%d: [", i);
        Vozlisce* w = v;
        while (w != NULL) {
            if (w != v) {
                printf(", ");
            }
            printf("%d", w->vsebina);
            w = w->desno;
        }
        printf("]\n");
        v = v->dol;
        i++;
    }

    printf("\n");
    printf("Originalna matrika -- po stolpcih:\n");
    v = v0;
    i = 0;
    while (v != NULL) {
        printf("%d: [", i);
        Vozlisce* w = v;
        while (w != NULL) {
            if (w != v) {
                printf(", ");
            }
            printf("%d", w->vsebina);
            w = w->dol;
        }
        printf("]\n");
        v = v->desno;
        i++;
    }
}

void _pocistiDiagonalo(Vozlisce* v) {
    while (v != NULL) {
        Vozlisce* temp = v->desno;
        free(v);
        v = temp;
    }
}

void _pocistiOriginal(Vozlisce* v0) {
    Vozlisce* v = v0;
    while (v != NULL) {
        Vozlisce* w = v;
        while (w != NULL) {
            Vozlisce* temp = w->desno;
            free(w);
            w = temp;
        }
        v = v->dol;
    }
}

int main() {
    _napolni();
    int vsota = 0;
    Vozlisce* diag = diagonala(_MATRIKA[0][0], &vsota);

    printf("vsota = %d\n\n", vsota);

    _izpisiDiagonalo(diag);
    _izpisiOriginal(_MATRIKA[0][0]);

    _pocistiDiagonalo(diag);
    _pocistiOriginal(_MATRIKA[0][0]);

    return 0;
}

#endif
