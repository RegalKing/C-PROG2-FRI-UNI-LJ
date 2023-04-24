#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

int main (){ 

    int length;
    scanf("%d",&length);

    int current=INT_MIN;
    int previous=INT_MIN;
    int equal=1;
    for (int i=0;i<length;i++){
        if (i==0){
            scanf("%d",&previous);
        }
        else{
            scanf("%d",&current);
            if (current!=previous){
                equal=0;
                break;
            }
            previous=current;
        }
    }

    printf("%d",equal);

}