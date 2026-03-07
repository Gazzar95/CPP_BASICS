/*
2/17/2025
UCSC Coding for Everyone: C and C++: https://www.coursera.org/specializations/coding-for-everyone
Part1- Module 3
Assignment 1 - Write a function that prints a table of values for sine and cosine between (0, 1)
*/

/*
 * print_sin_cos_table
 *
 * Purpose:
 *   Print a formatted table of x, cos(x), and sin(x) for x in [start, end]
 *   using a fixed step size.
 *
 * Inputs:
 *   start - starting x value (inclusive)
 *   end   - ending x value (inclusive)
 *   step  - increment per row (must be > 0)
 *
 * Outputs:
 *   Prints the table to stdout. Returns nothing.
 */

#include <stdio.h>
#include <math.h>

int main()
{
       double i = 0, c = 0, s = 0, id; // define objects

       printf("%9s%9s%9s\n", "Input", "Cosine", "Sine"); // pring table titles
       printf("%9.1f%9.1f%9.1f\n",
              i, c, s);

       for (i = 1; i <= 10; ++i)
       { // loop from 1 to 10 in intervals of 0.1
              id = i / 10.0;

              c = cos(id); // calculate cos
              s = sin(id); // calculate sine

              printf("%9.1f%9.1f%9.1f\n", // print putputs
                     id, c, s);
       }
       return 0;
}