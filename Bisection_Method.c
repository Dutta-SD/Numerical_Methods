/*
C program to implement Bisection Method
for approximating roots of equations 
*/

/* 
This method works to find the root by using binary search like
divide and conquer approach. We choose an interval [a, b]
such that f(a) and f(b) are of opposite sign. Then there 
is always a root of the eqaution between this interval.

Guess 1 for root: (a+b)/2 = xi
Assume f(a) is negative and f(b) is positive
Guess for 2 root: if f(x0) is negative, 
then root is in [xi, b] and in[a, xi] if 
it is positive
*/

/*
Iterations stop after a few iterations or if required precision 
is encountered . Precision/ Error is Epsilon.
Here precision is not implemented. Loop stops after 30 iterations.
*/


//This function is arbritrary. Any function with
//a real root will do.Chosen function is x^4 - 3*(x^2) + 4*x -1 

#include<stdio.h>
#include<stdlib.h>

//F takes the variable as input and returns functional values
//input: double
//output: double

double F(double x){
    return (x*x*x*x)-(3*x*x)+(4*x)-1;
}

//Epsilon = 0.001 is arbritrary choice. 

//Bisection_Method calculates the approximate roots of F(x)
//in the given interval.
//input : double, double
//output: None

void Bisection_Method(double a, double b){
	double Epsilon = 0.0001;
	double xi;                         //the variable which will have the extra roots
	int count = 0;
	
	xi = (a + b) / 2.0;                //Sets initial guess of approx root
	
	printf("%lf\n", xi);
	
	while(count!=30){                  //iterations stop after 30 runs
		if(F(xi) * F(a) > 0){      //if this condition is true, root is in [a, xi]
			a = xi;
			xi = (a+b) / 2.0;
			count++;
		}
		else if(F(xi) * F(a) < 0){   //if this condition is true, root is in [xi, b]
			b = xi;
			xi = (a+b) / 2.0;
			count++;
		}
			
	}
	printf("\nThe solution of the Equation is : %6.3lf", xi);	
}

int main(){
	double a, b;
	printf("Enter the values of a and b : ");
	scanf("%lf %lf", &a, &b);
	Bisection_Method(a, b);
	return EXIT_SUCCESS;	
}
