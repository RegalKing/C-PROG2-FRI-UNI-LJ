
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

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

    for (int i = 0;  i < stStudentov;  i++) {
        printf("[%d] P1 -> %d\n", i, poisciPO(studentje[i], "P1"));
        printf("[%d] P2 -> %d\n", i, poisciPO(studentje[i], "P2"));
        printf("[%d] FIZ -> %d\n", i, poisciPO(studentje[i], "FIZ"));
        printf("[%d] OMA -> %d\n", i, poisciPO(studentje[i], "OMA"));
        printf("[%d] ODV -> %d\n", i, poisciPO(studentje[i], "ODV"));
        printf("[%d] ARS -> %d\n", i, poisciPO(studentje[i], "ARS"));
        printf("\n");
    }

    return 0;
}
