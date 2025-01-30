/* Simple Interest */
/* Author Shubham Date 31/01/2025*/
#include<stdio.h>

int main()
{
    float n, p, r, si;
    printf("Enter Years: ");
    scanf("%f", &n);

    printf("Enter Principle Amount: ");
    scanf("%f", &p);

    printf("Enter Rate of Interest: ");
    scanf("%f", &r);

    si = (n*p*r)/100;
    printf("Simple Interest: %.2f", si);    // %.2f limits decimal places to 2.

    return 0;
}