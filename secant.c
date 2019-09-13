//This program is used to find the roots of the given equation using secant method.
//This method is based on the approximation of a curve as a secant in the close 
//neighbourhood of the root.
//Then we find out the iterations using the expression 
//x(k+1) = (-x(k).f(k-1) + x(k-1).f(k))/(f(k) - f(k-1)).
//Where x(k) and x(k-1) are the two approximations in the near neighbourhood
//of the root and f(k-1) and f(k) are the function values at the respective values
//of x.
//After finding out the x(k+1) value we take this one and x(k) to calculate next
//iteration.
//Given equation is x^2 + 5x + 2.
//Use -lm option of gcc while compiling the code and -o option to give a
//meaningfull objectcode filename.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float f(float );

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    fprintf(stderr,"Usage:- ./secant <guess1> <guess2>\n");
    exit(1);
  }
//Variable x0, x1, x2 are used for iterations calculations.
  float x0, x1, x2;
//Variable i is used as a iteration count.
  int i = 0;
  
  x0 = atof(argv[1]); 
  x1 = atof(argv[2]);
//While is used for iteration calculation until the value of function of 
//the both x values is equal.
  while (f(x0) != f(x1))
  {
//Incrementing the iteration count.
    i++;
//Finding out the next iteration.
    x2 = ((x0 * f(x1)) - (x1 * f(x0))) / (f(x1) - f(x0));
//Storing latest two iterations to calculate next iterations.
    x0 = x1;
    x1 = x2;
//Printing the latest iteration calculated.
    printf("Iteration %d :- %.10f\n", i, x2);
  }
//After finding the approximate root, printing the root value and number
//of iterations.
  printf("Root of the equation is %.10f\n", x2);
  printf("Iterations :- %d\n", i);

  return(0);
}
//This function finds the function value for given value of x.
float f(float x)
{
  return (pow(x, 2)) + (5 * x) + 2;
}
