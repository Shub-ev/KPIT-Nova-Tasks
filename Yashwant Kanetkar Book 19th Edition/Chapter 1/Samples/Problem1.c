/* Problem-1 */
/* 
Author: Shubham 
Date 31/01/2025
*/

/*
    Ramesh’s basic salary is input through the keyboard. His dearness
    allowance is 40% of basic salary, and house rent allowance is 20% of
    basic salary. Write a program to calculate his gross salary
*/

#include<stdio.h>

int main()
{
    float salary;
    printf("Enter salary: ");
    scanf("%f", &salary);

    float da = 0.4 * salary;
    float ha = 0.2 * salary;

    float grpay = salary + da + ha;
    printf("Ramesh's Dearness allowance: %.2f\n", da);
    printf("Ramesh's House Rent allowance: %.2f\n", ha);
    printf("Ramesh's Total Gross Salary: %.2f", grpay);

    return 0;
}