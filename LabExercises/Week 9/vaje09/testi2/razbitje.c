#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_subset(int *set, int setSize, bool *subset){
    printf("{");
    bool first=true;
    for (int i=0; i<setSize; i++){
        if (subset[i]){
            if (!first){
                printf(", ");
            } 
            else{
                first=false;
            }
            printf("%d", set[i]);
        }
    }
    printf("}\n");
}

void partition(int *set, int setSize, bool *subset, int position, int subset1sum, int subset2sum) {
    if (position==setSize){
        if (subset1sum==subset2sum){
            print_subset(set, setSize, subset);
        }
        return;
    }

    subset[position]=true;
    partition(set, setSize, subset, position + 1, subset1sum + set[position], subset2sum);

    subset[position]=false;
    partition(set, setSize, subset, position + 1, subset1sum, subset2sum + set[position]);
}

int main() {
    int setSize;
    scanf("%d", &setSize);

    int* set=malloc(setSize * sizeof(int));
    for (int i=0; i<setSize; i++){
        scanf("%d", &set[i]);
    }

    bool* subset=calloc(setSize, sizeof(bool));
    subset[0]=true;
    partition(set, setSize, subset, 1, set[0], 0);

    free(set);
    free(subset);
    return 0;
}