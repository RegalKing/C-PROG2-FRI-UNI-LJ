#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int main(){
    int length;
    scanf("%d",&length);
    int* tabela=calloc(length,sizeof(int));

    for (int i =0;i<length;i++){
        scanf("%d", &tabela[i]);
    }

    int sum=INT_MIN;
    int currentSum=0;

    for (int i=0;i<length;i++){
        currentSum+=tabela[i];

        if (currentSum>sum){
            sum=currentSum;
        }

        if (currentSum<0){
            currentSum=0;
        }
    }

    printf("%d",sum);
    free(tabela);
    return 0;
}
