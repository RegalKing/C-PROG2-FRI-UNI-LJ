
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

        //     for (int i=0;i<sizeOfArray;i++){               // odkomentiraj ce zelis videti podrobno delovanje
        //     if (i==0){
        //     printf("2:[%d,",array[i]);
        //     }
        //     if (i==sizeOfArray-1){
        //         printf("%d]\n",array[i]);
        //     }
        //     else
        //     {
        //         printf("%d,",array[i]);
        //     }
        // }

    for (int i=0;i<sizeOfArray;i++){
        if (i != sizeOfArray-1){ // ce je zadnji element arraya potem ne smemo plusa izpisat, zato minus ena
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

                                    
        // for (int i=0;i<size;i++){           // odkomentiraj ce zelis videti podrobno delovanje
        //     if (i==0){
        //     printf("1:[%d,",array[i]);
        //     }
        //     if (i==size-1){
        //         printf("%d]\n",array[i]);
        //     }
        //     else
        //     {
        //         printf("%d,",array[i]);
        //     }
        // }
        

        return;
    }
    if (n<0||k==0){
        return;
    }
    array[size]=k;

        //     for (int i=0;i<size;i++){           // odkomentiraj ce zelis videti podrobno delovanje
        //     if (i==0){
        //     printf("3:[%d,",array[i]);
        //     }
        //     if (i==size-1){
        //         printf("%d]\n",array[i]);
        //     }
        //     else
        //     {
        //         printf("%d,",array[i]);
        //     }
        // }
        

    list(array, size+1, n-k, k);
    list(array,size,n,k-1);
}
