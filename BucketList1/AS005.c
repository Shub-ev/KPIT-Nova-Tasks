/* AS005 */
/*  
    Author: Shubham Gharage  
    Date: 31/01/2025  
*/

/*
    Given an m x n binary matrix mat, return the number of special positions in mat.
    A position (i, j) is called special if mat[i][j] == 1 and 
    all other elements in row i and column j are 0 (rows and columns are 0-indexed).
*/

#include <stdio.h>
#include <stdlib.h>

/* Function to check if a row contains exactly one '1', and return its column index */
int checkRow(int** mat, int row, int cols) {
    int index = -1;
    for (int j = 0; j < cols; j++) {
        if (mat[row][j] == 1) {
            if (index != -1)  // More than one '1' in the row
                return -1;
            index = j;
        }
    }
    return index;  // Return the column index of the '1', or -1 if not found
}

/* Function to check if a column contains only one '1' at the given row index */
int checkColumn(int** mat, int rows, int col, int rowIndex) {
    for (int i = 0; i < rows; i++) {
        if (mat[i][col] == 1 && i != rowIndex) // Found another '1' in the column
            return 0;
    }
    return 1;  // Column contains only one '1'
}

/* Function to count special positions in the matrix */
int numSpecial(int** mat, int matSize, int* matColSize) {
    int specials = 0;

    for (int i = 0; i < matSize; i++) {
        int index = checkRow(mat, i, *matColSize);
        if (index >= 0 && checkColumn(mat, matSize, index, i))
            specials++;
    }

    return specials;
}

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        printf("Invalid input. Number of rows and columns must be positive integers.\n");
        return 1;
    }

    // Allocate memory for the matrix
    int** mat = (int**)malloc(rows * sizeof(int*));
    if (!mat) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        mat[i] = (int*)malloc(cols * sizeof(int));
        if (!mat[i]) {
            printf("Memory allocation failed!\n");
            for (int j = 0; j < i; j++) free(mat[j]); // Free allocated rows
            free(mat);
            return 1;
        }
    }

    // Input matrix elements
    printf("Enter the matrix elements (0 or 1):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &mat[i][j]) != 1 || (mat[i][j] != 0 && mat[i][j] != 1)) {
                printf("Invalid input. Matrix elements must be 0 or 1.\n");
                for (int k = 0; k < rows; k++) free(mat[k]);
                free(mat);
                return 1;
            }
        }
    }

    int result = numSpecial(mat, rows, &cols);
    printf("Number of special positions: %d\n", result);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
