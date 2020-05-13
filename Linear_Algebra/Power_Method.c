/*
C program to implement power method for finding dominating eigenvalue of a 
matrix.
*/

/* 
An eigen value of a matrix is a nonzero value l such that:
    AX = lX, where 
	A is the matrix,
	X is the eigenvector(non null)
	l is the eigenvalue.
	
A dominating eigen value lp is such that any other eigen value is smaller in 
magnitude than the magnitude of lp. Let the matrix has eigen values l1, l2,...
.., ln. A dominating eigen value is such that |lp| > |lj| for j=0, 1, 2; j not 
equal to p.

This method uses an initial approx for the eigen vector and then computes the 
next iteraton by multiplying it with the given matrix.The maximum value 
in the vector is extracted and then it is sent for multiplication again. 
When this error becomes small, the eigen value computed is the dominating 
eigen value, and the last computed matrix is the corresponding eigen vector. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*size is the dimensions of the square matrix.
Can be changed as per need*/

#define SIZE 3

/*
Matrix_Input takes the input for the augmented matrix of the system to be solved
    @Input : mat[SIZE][SIZE], where store the values
    @Output : None
*/

void Matrix_Input(double mat[SIZE][SIZE]) {
	int i, j;
	printf("ENTER THE MATRIX ELEMENTS[ %d x %d ]:\n", SIZE, SIZE);
	for(i = 0; i < SIZE; i++) {
		for(j = 0; j < SIZE; j++) {
			scanf("%lf", &mat[i][j]);
		}
	}
}

/*
MatMult is a function that multiplies the two matrices.
    @Input : A, B, C three matrices to be multiplied. The matrices are of 
    appropriate dimensions. The result is stored in C. A will be given.
    B will be previous eigenvector. C will be new eigenvector.
    @Output : None
*/

void MatMult(double A[SIZE][SIZE], double B[SIZE][1], double C[SIZE][1]) {
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

/*Max_Arr computes the maximum value in the given array.
    @Input : An array whose maximum value needs to be found.
    @Output : the maximum double value in the arr.
*/

double Max_Arr(double X[SIZE][1]) {
	double max;
	double temp[SIZE];
	int i;
	for(i=0;i<SIZE;i++) {
		temp[i] = fabs(X[i][0]);
	}
	max = temp[0];
	for(i = 0;i < SIZE; i++) {
		if(temp[i] > max) {
			max = temp[0];
		}
	}
	for(i = 0;i < SIZE; i++) {
		if(temp[i] + X[i][0] == 0.0) {
			return X[i][0];
		}
	}
}

/*
Divide_by_Eigen divides each element of matrix by eigen value.
    @Input : X, eigen_value
	@Output : None
*/

void Divide_by_Eigen(double X[SIZE][1], double eigen) {
	int i;
	for(i = 0;i < SIZE;i++) {
		X[i][0] = X[i][0] / eigen;
	}
}

/*
Power_method Calculates the Maximum eigen value for the given matrix.
    @Input : None
    @Output : None
*/

void Power_Method() {
	double A[SIZE][SIZE];
	int i, j;
	
	/*X is the Eigen_value, Xi is a temporary variable.*/
	
	double Eigen_value, Eigen_value_prev , X[SIZE][1], Xi[SIZE][1];
	double epsilon = 0.0001;
	
	Matrix_Input(A);            /*Inputted the require matrix*/
	
	for(i = 0; i < SIZE; i++){  /*Initialise EigenVector to [1, 1, 1...]*/
		X[i][0] = 1.0l;
	}
	
	MatMult(A, X, Xi);          /*Xi is temporary variable*/
        Eigen_value_prev = 0;        /*Random value for Eigenvalue initially*/
	Eigen_value = Max_Arr(Xi);
	Divide_by_Eigen(Xi, Eigen_value);
	
	
	for(i = 0; i < SIZE; i++){
		X[i][0] = Xi[i][0];       /*transfer from temporary to Eigen Vector*/
	}
	
	while(fabs((Eigen_value - Eigen_value_prev)) > epsilon) {
		Eigen_value_prev = Eigen_value;
		MatMult(A, X, Xi);
        	Eigen_value= Max_Arr(Xi);
        	Divide_by_Eigen(Xi, Eigen_value);
        	
	        for(i = 0; i < SIZE; i++){
		        X[i][0] = Xi[i][0];
        	}
	}
	
	printf("The eigen value is : %6.3lf ",Eigen_value);
	printf("\nThe corresponding EigenVector is :\n");
	for(i = 0;i < SIZE; i++) {
		printf("%6.3lf ", X[i][0]);
	}
 }
 
int main() {
	Power_Method();
	return EXIT_SUCCESS;
}










