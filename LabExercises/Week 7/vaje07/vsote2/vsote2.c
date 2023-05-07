
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

extern int list(int n, int k);

int main (){

    int n,k;
    scanf("%d%d",&n,&k);

    printf("%d\n",list(n,k));


}

int list(int n, int k){

    if (n==0){
        return 1;
    }
    if (n<0 || k==0){
        return 0;
    }
        return(list(n-k,k)+list(n,k-1));


}