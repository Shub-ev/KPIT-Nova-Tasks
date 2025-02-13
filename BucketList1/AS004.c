/* AS004 */
/*
    Author: Shubham Gharage
    Date: 31/01/2025
*/

/*
    The majority element is the element that appears more than ⌊n / 2⌋ times. 
    You may assume that the majority element always exists in the array.
*/

#include <stdio.h>
#include <stdlib.h>

/* Function to find the majority element using Boyer-Moore Voting Algorithm */
int majorityElement(int* nums, int numsSize) {
    int candidate = nums[0], count = 1;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }
    }
    return candidate;
}

int main() {
    int numsSize;

    printf("Enter the number of elements: ");
    if (scanf("%d", &numsSize) != 1 || numsSize <= 0) {
        printf("Invalid input. The number of elements must be a positive integer.\n");
        return 1;
    }

    // Allocate memory dynamically
    int* nums = (int*)malloc(numsSize * sizeof(int));
    if (!nums) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements: ");
    for (int i = 0; i < numsSize; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            free(nums);
            return 1;
        }
    }

    int result = majorityElement(nums, numsSize);
    printf("Majority Element: %d\n", result);

    // Free allocated memory
    free(nums);
    return 0;
}
