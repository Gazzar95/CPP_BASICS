/*
2/14/2025
UCSC Coding for Everyone: C and C++: https://www.coursera.org/specializations/coding-for-everyone
Part1- Module 2
Assignment 1 - Write a program that prints the sine function for an input x between (0, 1)
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    float x;
    float y;

    printf("input value between (0,1):\n");

    scanf("%f", &x);

    y = sin(x);

    printf("sine(%f) = %f", x, y);

    return 0;
}
