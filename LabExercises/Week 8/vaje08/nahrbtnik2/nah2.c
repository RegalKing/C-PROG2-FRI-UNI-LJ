#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Returns the optimal value of a filled backpack, we can only add items of greater index than "int index", we cannot subtract items
extern int optimalPrice(int numberOfObjects, int* pricesOfObjects, int* volumesOfObjects, int index, int oddVolumeCount, int maxOddVolumes, int BackpackVolumeSize);

int memo[1001][1001][1001];

int main () {

    int BackpackVolumeSize, numberOfObjects, maxOddVolumes;
    scanf("%d%d%d",&BackpackVolumeSize,&numberOfObjects,&maxOddVolumes);

    int* volumesOfObjects=malloc(numberOfObjects*sizeof(int));
    int* pricesOfObjects=malloc(numberOfObjects*sizeof(int));

    for (int i=0;i<numberOfObjects;i++){
        scanf("%d",&volumesOfObjects[i]);
    }

    for (int i=0;i<numberOfObjects;i++){
        scanf("%d",&pricesOfObjects[i]);
    }

    printf("%d",optimalPrice(numberOfObjects,pricesOfObjects,volumesOfObjects,0,0,maxOddVolumes,BackpackVolumeSize));

    free(volumesOfObjects);
    free(pricesOfObjects);
    return 0;

} 

int optimalPrice(int numberOfObjects, int* pricesOfObjects, int* volumesOfObjects, int index, int oddVolumeCount, int maxOddVolumes, int BackpackVolumeSize){
    
    if (index==numberOfObjects){
        return 0;
    }

    // Check memoization table
    if (memo[index][oddVolumeCount][BackpackVolumeSize] > 0){
        return memo[index][oddVolumeCount][BackpackVolumeSize];
    }

    // Option 1: Object with index "int index" is NOT ADDED to the backpack
    int maxPrice = optimalPrice(numberOfObjects, pricesOfObjects, volumesOfObjects, index+1, oddVolumeCount, maxOddVolumes, BackpackVolumeSize);
    
    // Option 2: Object with index "int index" is ADDED to the backpack, we move i+1 and subtract the object's volume from the total remaining backpack volume capacity
    if (volumesOfObjects[index]<=BackpackVolumeSize){
        int newOddVolumeCount = oddVolumeCount + (volumesOfObjects[index] % 2 != 0);
        if (newOddVolumeCount <= maxOddVolumes) {
            int price = pricesOfObjects[index] + optimalPrice(numberOfObjects, pricesOfObjects, volumesOfObjects, index+1, newOddVolumeCount, maxOddVolumes, BackpackVolumeSize - volumesOfObjects[index]);

            if (price>maxPrice){
                maxPrice=price;
            }
        }
    }

    // Save the optimal value in memoization
    memo[index][oddVolumeCount][BackpackVolumeSize] = maxPrice;

    return maxPrice;

}