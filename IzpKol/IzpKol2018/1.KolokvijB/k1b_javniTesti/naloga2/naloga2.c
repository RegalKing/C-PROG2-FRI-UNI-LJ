
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
int pojavitve(char* niz, char c, int* indeks) {
    int pojavitev=-1;
    int found=0;
    int count=0;

    for (int i=0;niz[i]!='\0';i++){
        if (niz[i]==c && found==0){
            pojavitev=i;
            found=1;
        }
        if (niz[i]==c){
            count++;
        }
    }
    *indeks=pojavitev;
    return count;
}

void naslednjaPojavitev(char* niz, int* indeks) {
    // indeks kazi na nek znak, na konc funkcije vpisi v isto spremenljivko naslednjo pojavitev oz -1 ce se ne pojavi vec
        char current=niz[*indeks];
        int index=*indeks;
        int found=0;
        *indeks=-1;

        for (int i=index+1;niz[i]!='\0';i++){
            if (niz[i]==current && found==0){
                found=1;
                *indeks=i;
            }
        }
}

char* kopijaPodniza(char* niz, char c, int k) {
    int prviIndeks=0;
    int prviIndeksFound=0;
    int drugiIndeks=0;
    int drugiIndeksFound=0;
    int count=0;
    for (int i=0;niz[i]!='\0';i++){
        if (niz[i]==c){
            count++;
        }
        if (niz[i]==c && prviIndeksFound==0 && k==count){
            prviIndeks=i;
            prviIndeksFound=1;
            
        }
        if (niz[i]==c && drugiIndeksFound==0 && k+1==count){
            drugiIndeks=i;
            drugiIndeksFound=1;
            break;
        }
    }
    // printf("1-%d,2-%d\n",prviIndeks,drugiIndeks); // DO TUKI DELA VSE LEPO
    int stCharUmes=0;
    for (int i=prviIndeks+1;i<drugiIndeks;i++){
        stCharUmes++;
    }

    int counterIndexa=0;
    char* seq=calloc(stCharUmes+1,sizeof(char));
    
    for (int i=prviIndeks+1;i<drugiIndeks;i++){
        seq[counterIndexa]=niz[i];
        counterIndexa++;
    }
    seq[counterIndexa]='\0';
    
    return seq;

}

int main() {
    // po "zelji dodajte kodo za ro"cno testiranje ...
    // add manual testing code if desired ...
    return 0;
}
