/* Problem-2 */
/* Author Shubham Date */
/*
    The distance between two cities (in kilometers) is input through the
    keyboard. Write a program to convert and print this distance in meters,
    feet, inches and centimeters. 
*/

#include<stdio.h>

int main()
{
    float dkm, dm, df, dcm;

    printf("Enter Distance (KM) : ");
    scanf("%f", &dkm);

    dm = dkm * 1000;
    dcm = dm * 100;
    df = 3.28084 * dm;

    printf("Distance (km) : %.2f\n", dkm);
    printf("Distance (meter) : %.2f\n", dm);
    printf("Distance (cm) : %.2f\n", dcm);
    printf("Distance (feet) : %.2f\n", df);

    return 0;
}