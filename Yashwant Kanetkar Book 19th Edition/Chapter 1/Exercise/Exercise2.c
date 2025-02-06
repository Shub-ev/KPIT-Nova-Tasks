/* Problem 2 */
/*
Author: Shubham
Date: 02/02/2004
*/

/*
    The length and breadth of a rectangle and radius of a circle are
    input through the keyboard. Write a program to calculate the area
    and perimeter of the rectangle, and the area and circumference of
    the circle. 
*/
#include<stdio.h>
#define PI 3.141592  // macro

int main()
{
    float l, b, r;
    printf("Enter Length of Rectangle: ");
    scanf("%f", &l);
    printf("Enter Breadth of Rectangle: ");
    scanf("%f", &b);
    printf("Enter Radius of Circle: ");
    scanf("%f", &r);

    printf("Area of Rectangle : %.3f units\n", (l*b));
    printf("Perimeter of Rectangle : %.3f units\n", (l+b) * 2);
    printf("Area of Circle : %.3f units\n", (PI * r * r));
    printf("Circumference of Circle : %.3f units\n", (2 * PI * r));

    return 0;
}