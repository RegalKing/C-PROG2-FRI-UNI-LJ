
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 *
 * Testni primeri:
 * 02--06: a = 1, b = n
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...   

void print_combinations(int arr[], int n, int a, int b, int index, int sum){
    if(sum==n && index>=a && index<=b){
        for(int i=0;i<index;i++) {
            printf("%d",arr[i]);
            if(i<index-1){
                printf("+");
            }
        }
        printf("\n");
    } else if(sum<n && index<b){
        int prev;
        if(index==0){
            prev=1;
        }
        else{
            prev=arr[index-1];
        }
        for(int i=prev;i<=n-sum;i++){
            arr[index]=i;
            print_combinations(arr,n,a,b,index+1,sum+i);
        }
    }
}

int main(){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    int arr[b];
    print_combinations(arr,n,a,b,0,0);
    return 0;
}




