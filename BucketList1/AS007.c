/* AS007 */
/*
    Author: Shubham Gharage
    Date: 01/02/2025
*/

/*

    You are given a string s of lowercase English letters and 
    an array widths denoting how many pixels wide each lowercase English letter is. 
    Specifically, widths[0] is the width of 'a', widths[1] is the width of 'b', and so on.
    
    You are trying to write s across several lines, where each line is no longer than 100 pixels. 
    Starting at the beginning of s, write as many letters on the first line such that 
    the total width does not exceed 100 pixels. Then, from where you stopped in s, 
    continue writing as many letters as you can on the second line. Continue this process until you have written all of s.
    
    Return an array result of length 2 where:
        result[0] is the total number of lines
        result[1] is the width of the last line in pixels.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* numberOfLines(int* widths, int widthsSize, char* s, int* returnSize) {
    int pixelWidth = 0, totalLines = 1;  // At least one line needed
    int len = strlen(s);

    // Handle empty string case
    if (len == 0) {
        *returnSize = 2;
        int* result = (int*)malloc(2 * sizeof(int));
        result[0] = 0;
        result[1] = 0;
        return result;
    }

    for (int i = 0; i < len; i++) {
        int charWidth = widths[s[i] - 'a'];
        if (pixelWidth + charWidth > 100) {
            totalLines++;
            pixelWidth = charWidth;
        } else {
            pixelWidth += charWidth;
        }
    }

    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = totalLines;
    result[1] = pixelWidth;
    return result;
}

int main() {
    int widths[26];
    char s[1001];

    printf("Enter 26 space-separated widths: ");
    for (int i = 0; i < 26; i++) {
        scanf("%d", &widths[i]);
    }
    getchar(); // Clear newline left by scanf

    printf("Enter the string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Remove newline if present

    int returnSize;
    int* result = numberOfLines(widths, sizeof(widths) / sizeof(widths[0]), s, &returnSize);

    printf("Lines needed: %d\n", result[0]);
    printf("Last line width: %d\n", result[1]);

    free(result);
    return 0;
}