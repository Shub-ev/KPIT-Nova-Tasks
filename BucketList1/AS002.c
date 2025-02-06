/* AS002 */
/*
Author: Shubham
Date: 29/01/2025
*/

/*
    Given a binary array nums, return the maximum number of consecutive 1's in the array.
    Input: nums = [1,1,0,1,1,1]
    Output: 3
    Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
*/

#include<stdio.h>
#include<stdlib.h>  // to use malloc
#define max(a,b) ((a) > (b) ? (a) : (b))    // macro to get the max value

int findMaxConsicutive(int* arr, int n){
    int maxCount = 0;
    int occurance = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] == 1) occurance++;
        else{
            maxCount = max(maxCount, occurance);
            occurance = 0;
        }
    }

    return max(maxCount, occurance);
}

int main()
{
    int n, maxConsicutive;
    int* arr;

    printf("Enter size of Binary Array: ");
    scanf("%d", &n);

    // dynamic memory allocation for array
    arr = (int*) malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Memory allocation failed!");
        return(1);
    }

    printf("Enter Array Elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    //function call
    maxConsicutive = findMaxConsicutive(arr, n);

    printf("Max Consecutive 1's: %d", maxConsicutive);

    free(arr);
}