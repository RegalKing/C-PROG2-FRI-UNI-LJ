
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

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

int main() {
    Student* studentje[] = {
        (Student[]) {333, (PO[]){{"FIZ", 10}, {"P1", 7}, {"P2", 8}, {"ODV", 9}, {"", 0}}, 4},
        (Student[]) {888, (PO[]){{"", 0}}, 0},
        (Student[]) {555, (PO[]){{"ARS", 6}, {"P2", 8}, {"ODV", 9}, {"", 0}}, 3},
        (Student[]) {111, (PO[]){{"OMA", 9}, {"", 0}}, 1},
        (Student[]) {777, (PO[]){{"P1", 10}, {"P2", 7}, {"", 0}}, 2},
        NULL
    };
    int stStudentov = sizeof(studentje) / sizeof(studentje[0]) - 1;

    izpisi(studentje, stStudentov);
    stStudentov = dodaj(studentje, stStudentov, 555, "ODV", 7);
    izpisi(studentje, stStudentov);

    return 0;
}
