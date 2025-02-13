/* AS008 */
/*
    Author: Shubham Gharage
    Date: 02/02/2025
*/

/*
    You are given a string s and an integer array indices of the same length. 
    The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.
    Return the shuffled string.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* restoreString(char* s, int* indices, int indicesSize) {
    char* res = (char*)malloc((indicesSize + 1) * sizeof(char));
    if (!res) return NULL;  // Handle memory allocation failure

    for (int i = 0; i < indicesSize; ++i) {
        res[indices[i]] = s[i];
    }
    res[indicesSize] = '\0';  // Null-terminate the string

    return res;
}

int main() {
    int indicesSize;
    printf("Enter the length of the string: ");
    scanf("%d", &indicesSize);

    char* s = (char*)malloc((indicesSize + 1) * sizeof(char));
    if (!s) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int* indices = (int*)malloc(indicesSize * sizeof(int));
    if (!indices) {
        printf("Memory allocation failed.\n");
        free(s);
        return 1;
    }

    printf("Enter the string: ");
    scanf("%s", s);

    printf("Enter %d indices: ", indicesSize);
    for (int i = 0; i < indicesSize; i++) {
        scanf("%d", &indices[i]);
        if (indices[i] < 0 || indices[i] >= indicesSize) {
            printf("Invalid index detected: %d\n", indices[i]);
            free(s);
            free(indices);
            return 1;
        }
    }

    char* shuffled = restoreString(s, indices, indicesSize);
    if (!shuffled) {
        printf("Memory allocation failed.\n");
        free(s);
        free(indices);
        return 1;
    }

    printf("Restored string: %s\n", shuffled);

    free(s);
    free(indices);
    free(shuffled);
    return 0;
}