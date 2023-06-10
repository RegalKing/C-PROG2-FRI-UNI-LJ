
/*
Ro"cno testiranje (npr. za primer test01.in):

gcc naloga3.c
./a.out < test01.in

Samodejno testiranje:

export name=naloga3
make test

Testni primeri:

test01: primer iz besedila
test02..test08: "se nekaj dodatnih testov

.in: testni vhod
.outA: pri"cakovani izhod (poljubna permutacija vrstic je tudi v redu)
.outB: pri"cakovani izhod za 0.6 to"cke (poljubna permutacija vrstic je tudi v redu)
.outC: pri"cakovani izhod za 0.3 to"cke (poljubna permutacija vrstic je tudi v redu)
.res: izhod va"sega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

#define MAX_LEN 100

void generate_strings(char *s, int len, char *result, int pos){
    if (pos == len){
        int has_lower = 0, has_upper = 0, has_digit = 0;

        for (int i = 0; i < len; i++){
            if (isdigit(result[i])){
                has_digit = 1;
            }
            else if (islower(result[i])){
                has_lower = 1;
            }
            else if (isupper(result[i])){
                has_upper = 1;
            }
        }

        if (has_digit && has_lower && has_upper){
            result[pos] = '\0';
            printf("%s\n", result);
        }

        return;
    }

    for (int i = 0; s[i] != '\0'; i++){
        result[pos] = s[i];
        generate_strings(s, len, result, pos + 1);
    }
}

int main(){
    int d, n;
    char s[MAX_LEN], result[MAX_LEN];

    scanf("%d %s %d", &d, s, &n);

    generate_strings(s, n, result, 0);

    return 0;
}