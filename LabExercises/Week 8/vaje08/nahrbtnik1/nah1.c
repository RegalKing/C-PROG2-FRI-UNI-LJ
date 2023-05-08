#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

#define MAX = 1000


// memo[index][volumeOfBackpack]
// 0 -> if we calculated optimalValue
// optValue -> if we calculated optValue, then the cell contains it
int memo[1001][1001]; // Meomization table

// Returns the optimal value of a filled backpack, we can only add items of greater index than "int index", we cannot subtract items
extern int optimalPrice(int numberOfObjects, int* pricesOfObjects, int* volumesOfObjects, int index, int volume);

int main () {

    // 12 - max prostornina nahrbtnika
    // 5 - stevilo edinstvenih predmetov
    // 3 4 7 2 3 - prostornine edinstvenih predmetov 
    // 5 6 8 9 1 - cene edinstvenih predmetov (cim visjo ceno moramo pridobiti brez da bi presegli prostornine 12)
    // 5+8+9=22 cena, V=3+7+2=12, je resitev v tem primeru

    int BackpackVolumeSize, numberOfObjects;
    scanf("%d%d",&BackpackVolumeSize,&numberOfObjects);

    int* volumesOfObjects=malloc(numberOfObjects*sizeof(int));
    int* pricesOfObjects=malloc(numberOfObjects*sizeof(int));

    for (int i=0;i<numberOfObjects;i++){
        scanf("%d",&volumesOfObjects[i]);
    }

    for (int i=0;i<numberOfObjects;i++){
        scanf("%d",&pricesOfObjects[i]);
    }

    printf("%d",optimalPrice(numberOfObjects,pricesOfObjects,volumesOfObjects,0,BackpackVolumeSize));

    free(volumesOfObjects);
    free(pricesOfObjects);
    return 0;

} 

int optimalPrice(int numberOfObjects, int* pricesOfObjects, int* volumesOfObjects, int index, int BackpackVolumeSize){
    
    if (index==numberOfObjects){
        return 0;
    }

    // We check, if we 
    if (memo[index][BackpackVolumeSize] > 0){
        return memo[index][BackpackVolumeSize];
    }

    // Option 1: Object with index "int index" is NOT ADDED to the backpack
    int maxPrice = optimalPrice(numberOfObjects, pricesOfObjects, volumesOfObjects, index+1, BackpackVolumeSize);
    
    // Option 2: Object with index "int index" is ADDED to the backpack, we move i+1 and subtract the object's volume from the total remaining backpack volume capacity
    if (volumesOfObjects[index]<=BackpackVolumeSize){
        int price = pricesOfObjects[index] + optimalPrice(numberOfObjects, pricesOfObjects, volumesOfObjects, index+1, BackpackVolumeSize - volumesOfObjects[index]);

        if (price>maxPrice){
            maxPrice=price;
        }
    }

    // Save the optimal value in memoization
    memo[index][BackpackVolumeSize]=maxPrice;

    return maxPrice;

}
