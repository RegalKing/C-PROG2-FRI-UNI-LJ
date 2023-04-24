#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

int main (){ 

    int m;
    int n;
    scanf("%d%d",&m,&n);
    int count=0;

    for (int i=1;i<n;i++){
        for (int j=i;j<n;j++){
            for (int k=m;k<=n;k++){
            if ( (i*i + j*j) ==  (k*k) ){
                printf("%d*%d(%d) + (%d)%d*%d=(%d)%d*%d\n",i,i,i*i,j*j,j,j,k*k,k,k);
                count++;
            }
            }
        }
    }
            
    printf("%d",count);

}