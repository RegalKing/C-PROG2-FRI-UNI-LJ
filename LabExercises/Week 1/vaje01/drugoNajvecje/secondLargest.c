#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

int main (){ 

    int length;
    scanf("%d",&length);

    int current=INT_MIN;
    int largest=INT_MIN;
    int secondlargest=INT_MIN;

    for (int i=0;i<length;i++){
        scanf("%d",&current);
        if (current>largest){
            secondlargest=largest;
            largest=current;
        }
        else if (current>secondlargest){
            secondlargest=current;
        }
    }

    printf("%d",secondlargest);      

}