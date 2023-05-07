
#ifndef _NALOGA_H
#define _NALOGA_H

typedef struct _PO {   // par predmet-ocena
    char predmet[4];   // oznaka predmeta
    int ocena;         // ocena pri tem predmetu
} PO;

typedef struct _Student {   // podatki o "studentu
    int vpisna;   // vpisna "stevilka
    PO* po;       // kazalec na za"cetek tabele parov predmet-ocena
    int stPO;     // "stevilo parov predmet-ocena
} Student;

int poisciStudenta(Student** studentje, int stStudentov, int vpisna);
int poisciPO(Student* student, char* predmet);
int dodaj(Student** studentje, int stStudentov, int vpisna, char* predmet, int ocena);

#endif
