#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

int main(){

    int length;
    scanf("%d",&length);

    int* numberExists=calloc(length,sizeof(int));

    int currentNumber;
    for (int i=0;i<length;i++){
        scanf("%d",&currentNumber);
        numberExists[currentNumber]+=1;
    }

    int no=0;
    for (int i=0;i<length;i++){
        if (numberExists[i]!=1){
            printf("NE");
            no=1;
        }
    }

    if (no==0){
        printf("DA");
    }


}