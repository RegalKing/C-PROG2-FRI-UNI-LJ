
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

extern void list(int* array, int size, int n, int k);
extern void listArrayNumbers(int* array, int sizeOfArray);

int main (){

    int n,k;
    scanf("%d%d",&n,&k);

    int* array=malloc(n*sizeof(int));// array za shranit vsote
    list(array,0,n,k);

    return 0;
}

void listArrayNumbers(int* array, int sizeOfArray){
    
    for (int i=0;i<sizeOfArray;i++){
        if (i != sizeOfArray-1){ // ce je zadnji element arraya potem ne smemo plusa izpisat
            printf("%d + ",array[i]);
        }
        else{
            printf("%d\n",array[i]);
        }
    }
}

void list(int* array, int size, int n, int k){
    if (n==0){
        listArrayNumbers(array, size);
        return;
    }
    if (n<0||k==0){
        return;
    }
    array[size]=k;
    list(array, size+1, n-k, k);
    list(array,size,n,k-1);
}
