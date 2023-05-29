
/*
Ro"cno testiranje (npr. za primer 01):

gcc naloga1.c
./a.out vhod01.pgm 150 izhod01.pgm
cmp izhod01.pgm ref01.pgm

Samodejno testiranje:

export name=naloga1
make test

Lahko si pomagate tudi s programom hexdump:

hexdump -C datoteka.pgm

Testni primeri:

01: primer iz besedila
02..07: vsaka pika je bodisi 0 bodisi 255
08..12: splo"sni primeri

Testne datoteke:

test*.par: argumenti ukazne vrstice
vhod*.pgm: vhodna slika
ref*.pgm: pri"cakovana izhodna slika
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================

int main(int argc, char** argv) {
    // dopolnite ...

    return 0;
}
