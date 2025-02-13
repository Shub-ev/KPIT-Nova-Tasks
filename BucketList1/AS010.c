/* AS010 */
/*
    Author: Shubham Gharage
    Date: 04/02/2025
*/

/*
    Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
    You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize) {
    int result = 0;

    // XOR all numbers together
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }

    return result;
}

int main() {
    int numsSize;
    printf("Enter the number of elements: ");
    scanf("%d", &numsSize);

    if (numsSize % 2 == 0) {
        printf("Invalid input! The number of elements must be odd.\n");
        return 1;
    }

    int* nums = (int*)malloc(numsSize * sizeof(int));
    if (!nums) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d elements: ", numsSize);
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    int result = singleNumber(nums, numsSize);
    printf("The single number is: %d\n", result);

    free(nums);
    return 0;
}
