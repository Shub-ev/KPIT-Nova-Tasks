/* AS003 */
/*
    Author: Shubham Gharage
    Date: 30/01/2025
*/

/*
    You are given a large integer represented as an integer array digits, 
    where each digits[i] is the ith digit of the integer. 
    The digits are ordered from most significant to least significant in left-to-right order. 
    The large integer does not contain any leading 0's. 
    Increment the large integer by one and return the resulting array of digits.
*/

#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    if (digitsSize <= 0) {
        *returnSize = 0;
        return NULL;
    }

    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) { 
            digits[i] += 1;  // Increment if not 9
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;  // Set to 0 if 9
    }

    // Case: All digits were 9 (e.g., 999 → 1000)
    int* newDigits = (int*)malloc((digitsSize + 1) * sizeof(int));
    if (newDigits == NULL) {
        printf("Memory allocation failed!\n");
        *returnSize = 0;
        return NULL;
    }
    
    newDigits[0] = 1;  // First digit is 1
    for (int i = 1; i <= digitsSize; i++) {
        newDigits[i] = 0;  // Fill remaining with 0
    }

    *returnSize = digitsSize + 1;
    return newDigits;
}

int main() {
    int digitsSize;
    printf("Enter the number of digits: ");
    scanf("%d", &digitsSize);

    if (digitsSize <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int* digits = (int*)malloc(digitsSize * sizeof(int));
    if (digits == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the digits: ");
    for (int i = 0; i < digitsSize; i++) {
        scanf("%d", &digits[i]);
    }

    int returnSize;
    int* result = plusOne(digits, digitsSize, &returnSize);

    printf("Result: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
    }
    printf("\n");

    // Free memory only if a new array was allocated
    if (result != digits) {
        free(result);
    }
    free(digits);

    return 0;
}