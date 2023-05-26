
/*
Ro"cno testiranje (npr. za primer test01.bin):

gcc naloga1.c
./a.out test01.bin

Samodejno testiranje:

export name=naloga1
make test

Testni primeri:

test01: primer iz besedila
test02: datoteka z bajtom 00000000
test03: datoteka z bajtom 10110111
test04..test06: samodejno izdelani, zgolj bajti 00000000 in 00000001
test07..test10: samodejno izdelani, splo"sni

.bin: testni vhod
.out: pri"cakovani izhod
.res: izhod va"sega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

int main(int argc, char** argv) {
    // dopolnite ...

    return 0;
}
