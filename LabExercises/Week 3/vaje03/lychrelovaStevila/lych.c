#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 100000000000000000L

// Function to reverse a number
long reverse(long num){
    long reversed=0;
    while (num>0){
        int digit=num%10;
        reversed=10*reversed+digit;
        num/=10;
    }
    return reversed;
}

// Function to check if a number is a palindrome
bool isPalindrome(long num){
    return num==reverse(num);
}

// Function to check if a number is a Lychrel number
bool isLychrelNumber(long num, int maxIterations){
    int i=0;
    do{
        num=num+reverse(num);
        i++;
    } while (i<maxIterations && num<=MAX_LENGTH && !isPalindrome(num));
    return !isPalindrome(num);
}

int main(){
    int maxIterations,lowerBound,upperBound;
    scanf("%d", &maxIterations);
    scanf("%d %d", &lowerBound, &upperBound);

    int lychrelCount = 0;
    for (int i=lowerBound;i<= upperBound;i++){
        if (isLychrelNumber(i, maxIterations))
            lychrelCount++;
    }
    printf("%d\n",lychrelCount);

    return 0;
}
