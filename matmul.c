#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>

#define RAND rand() % 100

void init_mat_sup ();
void init_mat_inf ();
void matmul ();
void matmul_sup ();
void matmul_inf ();
void print_matrix (float *M, int dim); // TODO

/* Usage: ./matmul <dim> [block_size]*/

int main (int argc, char* argv[])
{
	int block_size = 1, dim;
	float *A, *B, *C;


   dim = atoi (argv[1]);
   if (argc == 3) block_size = atoi (argv[2]); 

   // TODO

	exit (0);
}

void init_mat_sup (int dim, float *M)
{
	int i,j,m,n,k;

	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			if (j <= i)
				M[i*dim+j] = 0.0;
			else
				M[i*dim+j] = RAND;
		}
	}
}

void init_mat_inf (int dim, float *M)
{
	int i,j,m,n,k;

	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			if (j >= i)
				M[i*dim+j] = 0.0;
			else
				M[i*dim+j] = RAND;
		}
	}
}

void matmul (float *A, float *B, float *C, int dim)
{
	int i, j, k;

	for (i=0; i < dim; i++)
		for (j=0; j < dim; j++)
			C[i*dim+j] = 0.0;

	for (i=0; i < dim; i++)
		for (j=0; j < dim; j++)
			for (k=0; k < dim; k++)
				C[i*dim+j] += A[i*dim+k] * B[j+k*dim];
} 

void matmul_sup (float *A, float *B, float *C, int dim)
{
	int i, j, k;

	for (i=0; i < dim; i++)
		for (j=0; j < dim; j++)
			C[i*dim+j] = 0.0;

	for (i=0; i < (dim-1); i++)
		for (j=0; j < (dim-1); j++)
			for (k=(i+1); k < dim; k++)
				C[i*dim+j] += A[i*dim+k] * B[j+k*dim];
} 

void matmul_inf (float *A, float *B, float *C, int dim)
{
	int i, j, k;

	for (i=0; i < dim; i++)
		for (j=0; j < dim; j++)
			C[i*dim+j] = 0.0;

	for (i=1; i < dim; i++)
		for (j=1; j < dim; j++)
			for (k=0; k < i; k++)
				C[i*dim+j] += A[i*dim+k] * B[j+k*dim];
} 

