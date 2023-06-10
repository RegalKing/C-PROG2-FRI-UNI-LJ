
/*
 * Va"sa re"sitev prve naloge --- datoteko dopolnite in jo oddajte na spletno u"cilnico!
 *
 * Your solution to task 1 --- complete the file and submit it to U"cilnica!
 *
 * V naslednjo vrstico vpi"site va"so vpisno "stevilko / Enter your student ID number in the next line:
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    
    int n;
    scanf("%d",&n);

    char* znaki = malloc (2000*sizeof(char));
    int* distances = malloc (1000*sizeof(int));

    scanf("%s",znaki);

    int distance = 0;
    int checked = 0;

    int sum = 0;
    int distancesCount = 0;

    for (int i=0; znaki[i]!='\0'; i++){
        distance=0;
        if (znaki[i]=='+'){
            i++;
            distance++;
            while(znaki[i]=='-'){
                distance++;
                i++;
            }

            // printf("%d",distance);
        }
        if (znaki[i]=='+' && znaki[i-1]!='+'){
            i--;
        }

        if (distance!=0){
            sum+=distance;
            distancesCount+=1;
        }
    }

    printf("%d",(sum/distancesCount));
        
}