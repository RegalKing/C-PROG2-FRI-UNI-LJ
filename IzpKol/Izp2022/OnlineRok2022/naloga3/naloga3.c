
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
.outB: pri"cakovani izhod za 0.3 to"cke (poljubna permutacija vrstic je tudi v redu)
.res: izhod va"sega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate(char *S, char *result, int n, int pos, int* count){
    if (pos == n) {
        printf("%s\n", result);
        return;
    }

    for (int i = 0; i < strlen(S); i++){
        if (count[i] < 3) {
            result[pos] = S[i];
            count[i]++;

            generate(S, result, n, pos + 1, count);

            // Backtracking
            count[i]--;
            result[pos] = '\0';
        }
    }
}

int main(){
    int d, n;
    char S[51];

    scanf("%d %s %d", &d, S, &n);

    char* result = calloc((n+1), sizeof(char));
    int* count = calloc(d, sizeof(int));

    generate(S, result, n, 0, count);

    return 0;
}
