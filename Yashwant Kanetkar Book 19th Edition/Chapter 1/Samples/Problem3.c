/* Problem-3 */
/* Author Shubham Date */
/*
    If the marks obtained by a student in five different subjects are input
    through the keyboard, write a program to find out the aggregate marks
    and percentage marks obtained by the student. Assume that the
    maximum marks that can be obtained by a student in each subject is 100. 
*/
#include<stdio.h>

int main()
{
    int m1, m2, m3, m4, m5;
    printf("Enter mark 1: ");
    scanf("%d", &m1);

    printf("Enter mark 2: ");
    scanf("%d", &m2);

    printf("Enter mark 3: ");
    scanf("%d", &m3);

    printf("Enter mark 4: ");
    scanf("%d", &m4);

    printf("Enter mark 5: ");
    scanf("%d", &m5);

    int aggre = m1 + m2 + m3 + m4 + m5;
    float avg = (float)aggre/5.0;

    printf("Aggregate : %d/500\n", aggre);
    printf("Percentage: %.2f/100", avg);

    return 0;
}