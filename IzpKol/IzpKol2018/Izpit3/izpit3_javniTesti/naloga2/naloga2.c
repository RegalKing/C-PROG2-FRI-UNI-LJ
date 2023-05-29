
/*
 * Va"sa re"sitev druge naloge --- datoteko dopolnite in jo oddajte na spletno u"cilnico!
 *
 * Your solution to task 2 --- complete the file and submit it to U"cilnica!
 *
 * V naslednjo vrstico vpi"site va"so vpisno "stevilko / Enter your student ID number in the next line:
 *
 */

#include "naloga2.h"

Vozlisce* odstrani(Vozlisce* osnova, Vozlisce* indeksi) {
    
    Vozlisce* temp = osnova;

    int counterVozlisca = 0;
    int counterIndeksi = 0;

    do{
        counterVozlisca++;
        temp=temp->naslednje;
    } while (temp!=NULL);

    temp = indeksi; // temp prestavim na indekse
    do{
        counterIndeksi++;
        temp=temp->naslednje;
    } while (temp!=NULL);

    int* stevila = malloc (counterVozlisca*sizeof(int));
    int* indexes = malloc (counterIndeksi*sizeof(int));

    temp = osnova; // pointer temp dam nazaj na zacetek
    for (int i=0; i<counterVozlisca; i++){
        stevila[i]=temp->podatek;
        temp=temp->naslednje;
    }

    temp = indeksi; // pointer temp damo zdej na indeksi tabelo
    for (int i=0; i<counterIndeksi; i++){
        indexes[i]=temp->podatek;
        temp=temp->naslednje;
    }

    for (int i=0; i<counterIndeksi; i++){
        int currentIndex=indexes[0];
        stevila[currentIndex]= -1;              // oznacimo stevilo v tabeli kot -1 ce bo odstranjeno
    }

    int stevec = 0;
    int numbers = 0;
    Vozlisce* current = NULL;
    Vozlisce* next = NULL;
    while (stevec < counterIndeksi){
        if (stevila[numbers]!= -1){
                Vozlisce* temp2 = malloc(sizeof(Vozlisce));
                temp2->podatek=stevila[numbers];
                temp2->naslednje=NULL;
                if (current == NULL) {
                    current = temp2;
                    osnova = current;
                    stevec++;
                }
        }
        numbers++;

    }

}

int main() {
    // po "zelji dodajte kodo za ro"cno testiranje ...
    // add manual testing code if desired ...
    return 0;
}
