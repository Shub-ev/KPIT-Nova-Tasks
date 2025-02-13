/* AS006 */
/*
    Author: Shubham Gharage
    Date: 01/02/2025
*/

/*
    Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
    The order of the elements may be changed. Then return the number of elements in nums which are not equal to val. 
    Consider the number of elements in nums which are not equal to val be k, to get accepted, 
    you need to do the following things:
    
    Change the array nums such that the first k elements of nums contain the elements which are not equal to val. 
    The remaining elements of nums are not important as well as the size of nums. Return k.
*/


#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int k = 0; // Counter for elements that are not equal to val

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k; // New length of the array after removing val
}

int main() {
    int numsSize, val;
    printf("Enter the number of elements: ");
    scanf("%d", &numsSize);

    int nums[numsSize];
    printf("Enter the elements: ");
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter the value to remove: ");
    scanf("%d", &val);

    int newSize = removeElement(nums, numsSize, val);
    printf("New array size: %d\n", newSize);
    printf("Modified array: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
