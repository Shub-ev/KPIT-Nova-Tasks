/* Problem 4 */
/*
Author: Shubham
Date: 02-02-2025
*/

/* 
    Temperature of a city in Fahrenheit degrees is input through the
    keyboard. Write a program to convert this temperature into
    Centigrade degrees. 
*/
#include<stdio.h>

int main()
{
    int fahrenheit;
    printf("Enter temp (fahrenheit) : ");
    scanf("%d", &fahrenheit);

    float celsius = ((float)fahrenheit - 32) * 5/9;
    printf("Celsius : %.4f", celsius);

    return 0;
}