#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

void lex (int maxLength, char start, char end, char* tabela, int position){

    if (position==maxLength){
        return;
    }

    else{
        for (char current=start; current<=end ; current++){
            tabela[position]=current;
            tabela[position+1]=0;
            printf("%s\n",tabela);
            lex(maxLength,start,end,tabela,position+1);
        }
    }

}


int main () {

    int maxLength;
    char start,end;
    scanf("%d %c %c",&maxLength,&start,&end);
    // printf("%d,%c,%c",maxLength,start,end);

    char* tabela=calloc(maxLength+1, sizeof(char));

    lex(maxLength, start, end, tabela, 0);
        
    

}

