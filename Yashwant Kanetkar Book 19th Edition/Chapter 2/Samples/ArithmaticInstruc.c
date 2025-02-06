/* Arithmatic Instructions */
/*
Author: Shubham
Date: 02/02/2025
*/

/*
    *, /, -, + are the arithmetic operators. 
    = is an assignment operator.
    2, 5 and 3200 are integer constants.
    3.2 and 0.0056 are real constants. 

    C allows only one variable on left-hand side of =. That is, z = k * l is legal, whereas k * l = z is illegal.
    No operator is assumed to be present. It must be written explicitly.
    There is no operator in C to perform exponentiation operation. 
*/
#include<stdio.h>
#include<math.h>        // to perform pow()

int main()
{
    int a = 2;
    int b = 4;

    int c = a + b;

    // way to perform eponential arithmatic operations
    int d = pow(b,a);
    printf("%d\n",d);
}