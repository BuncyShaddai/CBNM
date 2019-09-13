/*This program is used to find the roots of the equation x^2 + 5x + 2 = 0 using
 *bisection method.
 *In this method, we first take two values in the close neighbourhood of the root.
 *Then we go on reducing the range by checking the function value of the mean of the 
  value taken and consecutively replacing them according the value obtained.
 *If f(mean) < 0 then mean becomes the lower bound of the range and vice versa.
 *By this method we get the root faster and more accurate than the iteration method.
*/
// Since functions are used , -lm option to be used with gcc.
// The program finds the roots upto 5 decimal places.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// Function Declaration
float f(float);

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    fprintf(stderr,"Usage: root1 <lowerval> <upperval>\n");
    exit(1);
  }
// Variable i for iteration count
  int i = 0;
/* Variable a , b for the range, mid for storing the mean and val for
 * storing the function value.
*/
  float a, b, mid, val;
// To check if the root lying in the range
  if (f(atof(argv[1])) * f(atof(argv[2])) > 0)
  {
    fprintf(stderr, "The root doesnt lie in between given guesses\n");
    exit(2);
  }
//To find out the lower limit and the upper limit from the inputs given
  if (f(atof(argv[1])) < 0 && f(atof(argv[2])) > 0)
  {
    a = atof(argv[1]);
    b = atof(argv[2]);
  }
  else
  {
    b = atof(argv[1]);
    a = atof(argv[2]);
  }
// While loop is used to find out the iterations
  while (i != 15)
  {
// Mean vlaue is calculated
    mid = (a + b) / 2;
// Function value at mean is calculated
    val = f(mid);
// To check whether the function value is less or greater than zero
    if (val > 0)
    {
      b = mid;
    }
    else
    {
      a = mid;
    }
// Incrementation of the iteration count
    i ++;
// Printing the iteration
    printf("Iteration %d :- %.10f\n", i, mid);
  }
// Printing the result
  printf("The approximate root is %.10f\n", mid);
  printf("Iterations = %d\n", i);
  return(0);
}
// This function returns the function value at a given number
float f(float x)
{
  return (pow(x, 2)) + (5 * x) + 2;
}
