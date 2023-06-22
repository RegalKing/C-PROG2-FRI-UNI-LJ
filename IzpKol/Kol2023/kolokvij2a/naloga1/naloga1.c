#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removePattern(char* string){
    char* patterns[] = {"\"c", "\"C", "\"z", "\"Z", "\"s", "\"S" };
    char replacements[] ={'c', 'C', 'z',  'Z', 's', 'S'};
    
    int len = strlen(string);
    //int numPatterns = sizeof(string)/sizeof(string[0]); RAČUNA SIZE POINTERJA, NE MOREŠ UPORABIT TEGA V METODI SAMO ZUNAJ METODE
    int numPatterns = 6;
    
    /*for(int i = 0; i < len; i++){
        for(int j = 0; j < numPatterns){
            if(strstr(patterns[j], str)){
            count++;
        }
    } */
    for(int i = 0; i < numPatterns; i++){
        char* pattern = patterns[i];
        char replacement = replacements[i];
        
        char* occurence = strstr(string, pattern);
        while(occurence != NULL){
            *occurence = replacement;
            memmove(occurence + 1, occurence + 2, strlen(occurence + 1)+1);
            occurence = strstr(occurence + 1, pattern);
        }
    }
    
}
int main(int arg, char** argv){
    char buffer[1000];
    FILE* in = fopen(argv[1], "r");
    if(in == NULL){
        printf("error opening file 1");
        exit(1);
    }
    FILE* out = fopen(argv[2], "w");
    if(out == NULL){
        printf("error opening file 2");
        exit(1);
    }
    while(fgets(buffer, sizeof(buffer), in) != NULL){
        removePattern(buffer);
        fputs(buffer, out);
    }
    printf("copied successfully");
    fclose(in);
    fclose(out);
    
return 0;
}