#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

int main() {
    int Number, SumI, SumII, i, j;
    scanf("%d", &Number);

    SumI=0;
    for(i=1;i<=Number/2;i++) {
        if(Number%i==0) {
            SumI+=i;
        }
    }

    SumII = 0;
    for(j=1;j<=SumI/2;j++) {
        if(SumI%j==0) {
            SumII+=j;
        }
    }

    if(SumII==Number&&Number!=SumI) {
        printf("%d & %d are friendly numbers\n", Number, SumI);
    } else {
        printf("NIMA\n");
    }

    return 0;
}
