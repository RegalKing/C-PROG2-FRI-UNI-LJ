
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

extern int stMoznosti(int n, int k);

int main (){

    int n,k;
    scanf("%d%d",&n,&k);

    printf("%d\n",stMoznosti(n,k));


}


//           stMoznosti(n,k)       -> funkcija nam bo povedala stevilo nacinov za zapis stevila N z vsoto, kjer je najvecja stevka manjsa ali enaka K
//         /                 \ 
//       / [k je del vsote]   \ [k ni del vsote, to pomeni da naprej gledamo za vse pod k] 
//     /                       \ 
//  stM(n-k,k)                 stM(n,k-1)
//
//  stM(n,k)= stM(n-k,k) + stM(n,k-1) -> to je splosni primer oziroma pogoj, pokriti je treba se robne primere, drugace bo rekurzija neskoncna

int stMoznosti(int n, int k){

    if (n==0){ // razlaga za robni primer: 0 se da zapisati na tocno en nacin -> 0=0
        return 1;
    }
    if (n<0 || k==0){ // n<0 razlaga -> ce je n negativno stevilo, potem ni moznih zapisov vsote stevila N z stevili z intervala [1,N], ker bi bila resitev v vsakem primeru pozitivno stevilo, zato
                      // ne bi bila nikoli enaka N

                      // namest n<0, lahko rajsi gledas ce je n<k -> stM(n,k)=stM(n,n) [razlaga: n bi se klical po stM(n,k-1) splosnem pogoju dokler ne bi prisel do stM(n,n) ]

                      // k==0 razlaga -> ce je k nic, potem po navodilu "na koliko načinov lahko število N zapišemo kot vsoto števil med 1 in vključno K", je interval med 1 in K [1,0]
                      // in posledicno ni resitev, ker je 1>0, 1 se ne da zapisati kot kakrsnokoli vsoto nicel
        return 0;
    }
        return(stMoznosti(n-k,k)+stMoznosti(n,k-1));


}