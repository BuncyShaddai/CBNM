//This program is used to find the roots of the given equation using regualr false method.
//This method is based on the approximation of a curve as a secant in the close 
//neighbourhood of the root.
//Then we find out the iterations using the expression 
//x(k+1) = (-x(k).f(k-1) + x(k-1).f(k))/(f(k) - f(k-1)).
//Where x(k) and x(k-1) are the two approximations in the near neighbourhood
//of the root and f(k-1) and f(k) are the function values at the respective values
//of x.
//Now we compare the function values of the latest iteration and previous iterations.
//The latest iteration and the iteration which gives the function value with opposite
//sign as that of the latest iterration is taken as the other value for finding
//next iteration.
//Given equation is x*log(x) - 1.2.
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
    fprintf(stderr,"Usage:- ./regularlog <guess1> <guess2>\n");
    exit(1);
  }
//Variable x0, x1, x2 are used for iterations calculations.
  float x0, x1, x2;
  int i = 1;
  
  x0 = atof(argv[1]); 
  x1 = atof(argv[2]);
//To check whether the inputs are within the range.
  if(x0 <= 0 || x1 <= 0)
  {
    fprintf(stderr,"Invalid input\n");
    exit(2);
  }
//An iteration is calculated before the while for comparisions.
  x2 = ((x0 * f(x1)) - (x1 * f(x0))) / (f(x1) - f(x0));
//Printing the iteration.
  printf("Iteration %d :- %.10f\n", i, x2);
//While is used for iteration calculation for 10 iterations.
  while (i != 10)
  {
//Incrementing iteration count.
    i++;
//Comparision of the function values to take required one.
    if (f(x1) * f(x2) < 0)
    {
      x0 = x1;
      x1 = x2;
    }
    else
    {
      x1 = x2;
    }
//Calculating the next iteration.
    x2 = ((x0 * f(x1)) - (x1 * f(x0))) / (f(x1) - f(x0));
//Printing the next iteration.
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
  return ((x * log10f(x)) - 1.2);
}
