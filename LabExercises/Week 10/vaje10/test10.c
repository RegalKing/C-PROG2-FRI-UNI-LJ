
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

char* PREDMETI[] = {"P1", "P2", "FIZ", "OMA", "ODV", "ARS", "DS", "APS", "LA", "VS"};
int ST_PREDMETOV = sizeof(PREDMETI) / sizeof(PREDMETI[0]);

void izpisi(Student** studentje, int stStudentov) {
    for (int i = 0;  i < stStudentov;  i++) {
        printf("%d: [", studentje[i]->vpisna);
        int stPO = studentje[i]->stPO;
        PO* po = studentje[i]->po;
        for (int j = 0;  j < stPO;  j++) {
            if (j > 0) {
                printf(", ");
            }
            printf("%s/%d", po[j].predmet, po[j].ocena);
        }
        printf("]\n");
    }
    printf("\n");
}

void pocisti(Student** studentje, int stStudentov) {
    for (int i = 0;  i < stStudentov;  i++) {
        free(studentje[i]->po);
        free(studentje[i]);
    }
}

int main() {
    Student* studentje[10];
    int stStudentov = 0;

    srand(123456789);
    for (int i = 0;  i < 100;  i++) {
        int vpisna = 100000 * (rand() % 9 + 1);
        char* predmet = PREDMETI[rand() % ST_PREDMETOV];
        int ocena = rand() % 5 + 6;
        stStudentov = dodaj(studentje, stStudentov, vpisna, predmet, ocena);
    }

    izpisi(studentje, stStudentov);
    pocisti(studentje, stStudentov);

    return 0;
}
