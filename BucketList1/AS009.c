/* AS009 */
/*
    Author: Shubham Gharage
    Date: 03/02/2025
*/

/*
    Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets.
    A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:
    0 <= i < j < k < arr.length
    |arr[i] - arr[j]| <= a
    |arr[j] - arr[k]| <= b
    |arr[i] - arr[k]| <= c
    
    Where |x| denotes the absolute value of x.
    Return the number of good triplets.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int countGoodTriplets(int* arr, int arrSize, int a, int b, int c) {
    int count = 0;

    for (int i = 0; i < arrSize - 2; i++) {
        for (int j = i + 1; j < arrSize - 1; j++) {
            if (abs(arr[i] - arr[j]) > a) continue;  // Skip unnecessary iterations
            for (int k = j + 1; k < arrSize; k++) {
                if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    int arrSize;
    printf("Enter the size of the array: ");
    scanf("%d", &arrSize);

    if (arrSize < 3) {
        printf("Array size must be at least 3.\n");
        return 1;
    }

    int* arr = (int*)calloc(arrSize, sizeof(int));  // Use calloc to initialize memory
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements: ", arrSize);
    for (int i = 0; i < arrSize; i++) {
        scanf("%d", &arr[i]);
    }

    int a, b, c;
    printf("Enter values for a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);

    int result = countGoodTriplets(arr, arrSize, a, b, c);
    printf("Number of good triplets: %d\n", result);

    free(arr);
    return 0;
}
