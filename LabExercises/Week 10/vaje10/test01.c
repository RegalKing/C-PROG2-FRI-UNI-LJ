
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

    for (int vpisna = 111;  vpisna <= 999;  vpisna += 111) {
        printf("%d -> %d\n", vpisna, poisciStudenta(studentje, stStudentov, vpisna));
    }

    return 0;
}
