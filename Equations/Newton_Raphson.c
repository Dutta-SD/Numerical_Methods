/*C code to implement Newton Raphson Method for solving complicated equations*/

/*This method uses an initial approximation of of a root X. Then it computes
the next iteration by the formula x(i+1) = x(i) - f(x(i))/f'(x(i)).
The method has quadratic convergence. The loop stops when the error or 
abs(x(i+1)/x(i)) becomes less than a predefined value Epsilon. 
The method has very fast convergence rate(Quadratic) if the initial 
approximation is very close to the original root.
Multiple roots may cause a problem. Also if the multiple roots are so close 
that their difference is less than the predefined
precision value then this method might cause problems. */

/*This Method is generally used with Bisection or False Position Method for
getting a very good approximation of the root of the function. 
This method can be used to solve polynomial and transcendetal equations. */

#include<stdio.h>
#include<stdlib.h>

/* F returns the value of the function whose roots we want to calculate. 
  @Input : double x
  @Output : double F(x) that is the functional value */
  
double F(double x){
	return ( x * x * x )- ( x * x )+ x - 1;
}

/*F_ function returns the derivative value of the function we want to calc.
@Input : double x
@Output : double F_(x) that is the value of the derivative of the function */

double F_(double x){
	return ( 3 * x * x )- ( 2 * x )+ 1 ;
}

/* Newton_Raphson function gives approximate root of the polynomial.
@Input : double X(approximate first root)
@Output : None
*/

void Newton_Raphson(double X){
	double Epsilon = 0.01;                   //Epsilon is Error / Precision
	double X_temp;                           //Temp var, stores X of prev iter.
	
	while(abs( X - X_temp) > Epsilon){      //while iterations not sufficiently
		X_temp = X;                         //close, loop continue
		X = X - F(X) / F_(X);	
	}
	
	printf("The Root of the Equation is : %6.4lf", X);  //6 significant digits
}

int main(){
	double X_initial;
	
	printf("Enter Approximate first value : ");
	scanf("%lf", &X_initial);
	Newton_Raphson(X_initial);
	return EXIT_SUCCESS;
}
