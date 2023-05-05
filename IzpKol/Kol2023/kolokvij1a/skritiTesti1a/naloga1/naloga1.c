
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// po potrebi dopolnite ...

extern int sum(int* stevilke,int numbers);
extern int pal(int* stevilke,int numbers);

int main() {
    
    int numbers;
    scanf("%d",&numbers);

    int* stevilke=calloc(numbers,sizeof(int));

    for (int i=0;i<numbers;i++){
        scanf("%d",&(stevilke[i]));
    }



   
    int j=pal(&(stevilke[0]),numbers);
    if (j==0){
        printf("DA\n");
    }
    else{
        printf("NE\n");
    }
    
    printf("%d",sum(&(stevilke[0]),numbers));

}

extern int sum(int* stevilke,int numbers){
    int sum1=0;
    for (int i=0;i<numbers;i++){
        sum1+=stevilke[i];
    }
    return sum1;
}

extern int pal(int* stevilke,int numbers){
    int numbersCount=numbers-1;
    int niPalindrom=0;
    for (int i=0;i<(numbers)/2;i++){ // PREVERI DA JE N-1
        if (stevilke[i]==stevilke[numbersCount]){
            // printf("%d (%d)=(%d) %d\n",stevilke[i],i,numbersCount,stevilke[numbersCount]);
        }
        else {
            // printf("%d (%d)!=(%d) %d\n",stevilke[i],i,numbersCount,stevilke[numbersCount]);
            niPalindrom=1;
            break;
        }
        numbersCount--;
    }
    return niPalindrom;
            
    }







