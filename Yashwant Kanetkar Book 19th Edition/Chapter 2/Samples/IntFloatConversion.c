/*  */
/*
Author: Shubham
Date: 03/02/2025
*/

/*
    1. An arithmetic operation between an integer and integer always yields an integer result.
    2. An operation between a real and real always yields a real result.
    3. An operation between an integer and real always yields a real result. In this operation, 
       the integer is first promoted to a real and then the operation is performed. Hence the result is real. 
    4. If types of expressions on RHS and LHS of = are not same then the value
    of the expression on RHS is promoted or demoted depending on the type of the variable on left-hand side of =. 
*/

#include<stdio.h>

int main()
{
    int n = 2.5;  // n = 1
    float f = 5;  // f = 5.0

    float res1 = 5/2; // res = 2;
    float res2 = 5.0/2; // res = 2.5;
    printf("%.1f", res2);
}