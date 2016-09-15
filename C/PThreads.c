// PThreads.cpp : Defines the entry point for the console application.
//

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

#define M 15000
#define K 2
#define N 3
#define NUM_THREADS 10

int A[M][K];
int B[M][K];
int c[M][K];

struct v {
	int i; //Linea
	int j; //Columna
	
};

void *runner(void *param); //El thread

int main(int argc, char *argv[]) {

	int f, g;
	for (f = 0; f < 15000; f++)
	{
		for(g = 0; g < 2; g++){
			srand(time(NULL));
			A[f][g] = rand();
			B[f][g] = rand();
		}
	}


	printf("%s", "Starting calculation");
	printf("\n");
	clock_t begin = clock();
	int i, j, count = 0;
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			struct v *data = (struct v*) malloc(sizeof(struct v));
			data->i = i;
			data->j = j;
			pthread_t tid; //ID del thread
			pthread_attr_t attr; //atributos del thread
			pthread_attr_init(&attr);
			
			pthread_create(&tid, &attr, runner, data);
			pthread_join(tid, NULL);
			count++;
			
		}
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

		/*
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ", c[i][j]);
			
		}
	}
	printf("\n");
	*/

	printf("%lf", time_spent);
	printf("\n");
}

void *runner(void *param) {
	struct v *data = param;
	int n, sum = 0;
	
	for (n = 0; n < K; n++) {
		sum += A[data->i][n] * B[n][data->j];
		
	}
	c[data->i][data->j] = sum;
	
	pthread_exit(0);
	
}

