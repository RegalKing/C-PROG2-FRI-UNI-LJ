
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"

int poisciStudenta(Student** studentje, int stStudentov, int vpisna) {
    
    for (int i=0; i<stStudentov; i++){
        if (studentje[i]->vpisna == vpisna){
            return i;
        }
    }
    return -1;

}

int poisciPO(Student* student, char* predmet) {

     for (int i=0; i<student->stPO; i++){
        if (!(strcmp((student->po[i].predmet),predmet))){
            return i;
        }
     }
    return -1;
}


// za funkcijo "dodaj" razlaga:
// 1. moznost) ce student z vpisno se ne obstaja -> dodamo novega studenta na mesto v "studentje" ki je NULL (potem moramo po njem dodati tudi nov NULL), zanj dodamo da je ta predmet naredil z to oceno

// 2. moznost) student ze obstaja, vendar predmeta se ni delal -> dodamo na konec PO (v prvo prazno celico) njegov predmet in oceno

// 3. moznost) student obstaja in ta student je ze delal predmet -> novo oceno vpisi v del ocena od predmeta


int dodaj(Student** studentje, int stStudentov, int vpisna, char* predmet, int ocena) {
    
    int indexStudenta = poisciStudenta(studentje, stStudentov, vpisna);

    if (indexStudenta == -1){ // student v tabeli "studentje" se ne obstaja, zato ustvarimo novo strukturo
                              // in kazalec nanjo vpisemo v prvo prosto mesto v tabeli
        Student* novStudent = malloc(sizeof(Student));

        novStudent->vpisna=vpisna;
        novStudent->stPO=1;
        novStudent->po=malloc(10 * sizeof(PO));

        strcpy(novStudent->po[0].predmet , predmet);
        novStudent->po[0].ocena=ocena;

        studentje[stStudentov]=novStudent;
        stStudentov++;
    }
    else{ // student obstaja v tabeli "studentje"
        Student* stud=studentje[indexStudenta]; // pointer na studenta, da bo manj za pisat

        int indexPredmeta = poisciPO(stud , predmet);

        if (indexPredmeta == -1){ // predmeta se ni pri studentu 
            strcpy(stud->po[stud->stPO].predmet , predmet);
            stud->po[stud->stPO].ocena=ocena;
            stud->stPO++;
        }
        else{ // student je predmet ze opravljal
         stud->po[indexPredmeta].ocena=ocena;
        }
    }
    return stStudentov;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
