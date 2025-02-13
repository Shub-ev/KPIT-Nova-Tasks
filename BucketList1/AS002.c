/* AS002 */
/*
    Author: Shubham Gharage
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

int findMaxConsecutive(int* arr, int n) {
    if (n == 0) return 0;  // Handle empty array case

    int maxCount = 0;
    int occurrence = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            occurrence++;
        } else {
            maxCount = max(maxCount, occurrence);
            occurrence = 0;
        }
    }

    return max(maxCount, occurrence);
}

int main() {
    int n, maxConsecutive;
    int* arr;

    printf("Enter size of Binary Array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    // Dynamic memory allocation for array
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter Array Elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Function call
    maxConsecutive = findMaxConsecutive(arr, n);

    printf("Max Consecutive 1's: %d\n", maxConsecutive);

    free(arr);
    return 0;
}
