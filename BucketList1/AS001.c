/* AS001 */
/*
    Author: Shubham Gharage
    Date: 29/01/2025
*/

/*
    You are given a sorted unique integer array nums.
    A range [a,b] is the set of all integers from a to b (inclusive).
    Return the smallest sorted list of ranges that cover all the numbers in the array exactly.
    That is, each element of nums is covered by exactly one of the ranges, 
    and there is no integer x such that x is in one of the ranges but not in nums.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_RANGE_LENGTH 25  // Maximum length for each range string

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Allocate memory for result array
    char** result = (char**)malloc(numsSize * sizeof(char*));
    if (!result) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    *returnSize = 0;
    int start = nums[0];

    for (int i = 1; i <= numsSize; ++i) {
        // If end of range is reached
        if (i == numsSize || nums[i] != nums[i - 1] + 1) {
            result[*returnSize] = (char*)malloc(MAX_RANGE_LENGTH * sizeof(char));
            if (!result[*returnSize]) {
                printf("Memory allocation failed.\n");
                exit(1);
            }

            if (start == nums[i - 1]) {
                sprintf(result[*returnSize], "%d", start);
            } else {
                sprintf(result[*returnSize], "%d->%d", start, nums[i - 1]);
            }

            (*returnSize)++;
            if (i < numsSize) start = nums[i]; // Start a new range
        }
    }
    return result;
}

int main() {
    int numsSize;

    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    if (scanf("%d", &numsSize) != 1 || numsSize < 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    // If no elements, exit early
    if (numsSize == 0) {
        printf("No elements provided.\n");
        return 0;
    }

    // Allocate memory for nums array
    int* nums = (int*)malloc(numsSize * sizeof(int));
    if (!nums) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Get array elements
    printf("Enter %d sorted unique elements: ", numsSize);
    for (int i = 0; i < numsSize; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            free(nums);
            return 1;
        }
    }

    int returnSize;
    char** ranges = summaryRanges(nums, numsSize, &returnSize);

    // Print summary ranges
    printf("Summary Ranges:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", ranges[i]);
        free(ranges[i]); // Free each range string
    }

    // Free allocated memory
    free(ranges);
    free(nums);
    
    return 0;
}
