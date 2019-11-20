/* C program to implement Bisection Method
for solving non linear equations
*/

/* This method works to find the root by using binary search like
divide and conquer approach. We choose an interval [a, b]
such that f(a) and f(b) are of opposite sign. Then there is always a root 
of the eqaution between this interval.
*/

/*Guess 1 for root: (a+b)/2 = x0
Assume f(a) is negative and f(b) is positive
Guess for 2 root: if f(x0) is negative, 
then root is in [x0, b] and in[a, x0] if 
it is positive
*/

/*Iterations stop after a few iterations or if required precision 
is encountered . Precision/ Error is Epsilon
*/


//This function is arbritrary. Any function with
//a real root will do.Chosen function is x^3 - x^2 + x - 1  

#include<stdio.h>
#include<stdlib.h>
	
double F(double x){
    return (x*x*x*x)-(3*x*x)+(4*x)-1;
}

//Let chosen interval be [-1, 2]. Epsilon = 0.001

void Bisection_Method(double a, double b){
	double Epsilon = 0.0001;
	double xi;
	int count = 0;
	
	xi = (a + b) / 2.0;
	printf("%lf\n", xi);
	
	while( count!=30){
		if(F(xi) * F(a) > 0){
			a = xi;
			xi = (a+b) / 2.0;
			count++;
		}
		else if(F(xi) * F(a) < 0){
			b = xi;
			xi = (a+b) / 2.0;
			//printf("%lf ", xi);
			count++;
		}
			
	}
	printf("\nThe solution of the Equation is : %14.13lf", xi);	
}

int main(){
	double a, b;
	printf("Enter the values of a and b : ");
	scanf("%lf %lf", &a, &b);
	Bisection_Method(a, b);
	return EXIT_SUCCESS;	
}
