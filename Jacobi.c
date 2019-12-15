/*
C program to implement jacobi's method for solving a system of 
linear equations.

Jacobis method works when all of the diagonal elements of the 
augmented matrix is not equal to 0. 
So we can rearrange the equations to write:

        x1 = b1/a11 - a12/a11 x2 - a13/a23 x3 -...        (1)
        x2 = b2/a22 - a21/a22 x1 - a23/a22 x3 -...
        x3 = b3/a33 - a31/a33 x1 - a32/a33 x2 -...
        .
        .
        
 and so on for all equations.
*/

/*
We then take an initial approximate value for each of x1, x2, x3, ... and 
then from (1) and the other equations we obtain the next approximations for the 
values of x1, x2, x3...

We continue this process till the difference between two successive 
approximations does not become smaller than epsilon(specified).

*/

/*
This method is guarenteed to converge if the diagonal elements of the matrix
are non-zero and S = [sum of absolute value of the coefficients (aij/aii)
where j runs from 1 to n, j != i, i runs from  1 to n] is <=1 ie S <= 1.

In matrix notation, the process is written as:
    X(n+1) = BX(n) + C
    where, 
    X(n+1)  is the (n+1)th approx to the variables,
    X(n)    is the (n)th approx to the variables, 
    B       is the coefficient matrix after rearrangement, 
    C       is the constant matrix [b1/a11, b2/a22, ...]
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>       //for fabs() function

#define SIZE 3        //as we are taking 3x3 matrices

/*
Augmented Matrix Input takes the input for the augmented matrix of the 
system to be solved.
    @Input : mat[SIZE][SIZE+1] as augmented matrix
    @Output : None
*/

void Augmented_Matrix_Input(float mat[SIZE][SIZE+1]) {
	int i, j;
	printf("ENTER THE MATRIX ELEMENTS:\n");
	for(i = 0; i < SIZE; i++) {
		for(j = 0; j < SIZE + 1; j++) {    //augmented matrix, size+1
			scanf("%f", &mat[i][j]);
		}		
	}	
}

/*
MatMult is a function that multiplies the two matrices.
    @Input : A, B, C three matrices to be multiplied. The matrices are of 
    appropriate dimensions. The result is stored in C.
    @Output : None
*/

void MatMult(float A[SIZE][SIZE], float B[SIZE][1], float C[SIZE][1]) {
	int i, j, k;
	for(i = 0; i < SIZE; i++) {
		for(j = 0; j < 1; j++) {
		    C[i][j] = 0;
			for(k = 0; k < SIZE; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}		
		}		
	}	
}

/*
MatAdd is a function to add two matrices.
    @Input : A, B, C three float matrices of apt dimensions. The addition is 
    handled in the function only and stored in C.
    @Output : None
*/

void MatAdd(float A[SIZE][1], float B[SIZE][1], float C[SIZE][1]) {
	int i, j;
	for(i = 0; i < SIZE; i++) {
		for(j = 0;j < 1;j++) {
		C[i][j] = A[i][j] + B[i][j];
	    }	    	    
	}	
}

/*
Jacobi function calculates the solutions for the system.
    @Input : float pointer mat, the augmented matrix for the system.
	The calculation is done inside the function and the result is shown.
    @Output : None
*/

void Jacobi(float mat[SIZE][SIZE+1]) {
	float B[SIZE][SIZE];           
	float C[SIZE][1];
	float X[SIZE][1];
	
	int i, j;
	
	//epsilon is the required precesion, can change its value
	
	float epsilon = 0.0001;
	float prev_val;
	
	//Initial approx is [0, 0, 0....]
	
	for(i = 0; i < SIZE ; i++) {
		X[i][0] = 0;                      
	}
	
	//Check if diagonal elements are non zero.
	
	for(i = 0; i<SIZE; i++) {
		if(fabs(mat[i][i] - 0.0) < epsilon){
			printf("CANNOT SOLVE!!!\n");
			return EXIT_FAILURE;
		}
	}
	
	//Sets the matrix B as per structure shown above
	
	for(i = 0; i < SIZE; i++) {
		for(j = 0; j < SIZE ; j++) {   
			if(i!=j) {
				B[i][j] = - mat[i][j] / mat[i][i];				
			} else {
				B[i][j] = 0;
			}
		}		
	}
	
	for(i = 0;i < SIZE; i++){
		C[i][0] = mat[i][SIZE] / mat[i][i];		
	}
	
	//Sets initial Value of prev_val
	
	MatMult(B, X, X);
	MatAdd(C, X, X);
	prev_val = 0.0;
	
	//Iterates repeatedly till convergence
	
	while(fabs(X[0][0] - prev_val) > epsilon) {
		prev_val = X[0][0];
		MatMult(B, X, X);
	    MatAdd(C, X, X);	
	}
		
	//prints final result
	
	for(j=0;j<SIZE;j++) {
		printf("X[%d] = %f\n", j, X[j][0]);
	}	
}

int main(){
	float mat[SIZE][SIZE+1];
	Augmented_Matrix_Input(mat);
	Jacobi(mat);
	return EXIT_SUCCESS;	
}


