/*C program for implementation and comparison of Eulers Method,
Modified Eulers method, Runge Kutta Method(2nd order and 4th order formula)
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
We write
    y' = f(x, y)
	Initial Value : (x0, y0)
*/
double f(double x, double y) {
	/* Let us take dy/dx = x*x + y , (0,0) as the initial value */
	return x*x + y;
}
/* We will find out the value in [0, 0.5], step size 0.01 */
void Euler_Method() {
	double x0 = 0.0, y0 = 1.0, h = 0.05;
	int i;
	printf("\n\tEulers Method for Solving Differential Equations \n");
	for(i = 0;i < 5; i++) {
		printf("X : %lf\tY : %lf\n", x0, y0);
		y0 = y0 + h * f(x0, y0);
		x0 = x0 + h;
	}
}

/*Calculates the value for a particular point. */
void Modified_Euler(double x0, double y0, double h) {
	double y1 = y0 + h*f(x0, y0), x1 = x0+h, temp = 0.0;
 	printf("\n\tEulers Modified Method for Solving Differential Equations \n");
	while(fabs(temp - y1)>0.00000001) {
		temp = y1;
		y1 = y0 + ( f(x0, y0) + f(x1, y1) ) * h / 2.0;
	}
	printf("X = %lf\tY = %lf\n", x1, y1);
}

void Runge_Kutta_2nd_Order() {
	double x0 = 0.05, y0 = 1.0513, h = 0.05, k1, k2;
	printf("\n\tRunge Kutta 2nd Order Method for Solving Differential Equations \n");
		k1 = h*f(x0, y0);
	    k2 = h*(x0 + h, y0 + k1);
        y0 = y0 + (k1+k2) / 2.0;
        x0 += h;
        printf("X : %lf\tY : %lf\n", x0, y0);
}

void Runge_Kutta_4th_Order() {
	double x0 = 0.05, y0 = 1.0513, h = 0.05, k1, k2, k3, k4;
	printf("\n\tRunge Kutta 4th Order Method for Solving Differential Equations \n");
		k1 = h*f(x0, y0);
	    k2 = h*(x0 + h/2.0, y0 + k1/2.0);
	    k3 = h*f(x0 + h/2.0, y0 + k2/2.0);
	    k4 = h*f(x0 + h, y0 + k3);
        y0 = y0 + (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        x0 += h;
        printf("X : %lf\tY : %lf\n", x0, y0);
}



int main() {
	Euler_Method();
	Modified_Euler(0.1, 1.0513, 0.05);
	Runge_Kutta_2nd_Order();
	Runge_Kutta_4th_Order();
	return EXIT_SUCCESS;
}


