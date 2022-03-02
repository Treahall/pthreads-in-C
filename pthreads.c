#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_THREADS 4
#define NUM_ITERATIONS 10000

// Global variable that the threads increment.
static int counter;

void *increment(void *num)
{
	/*This function increments the global counter by num.*/
	printf("A thread is incrementing!\n");
	int i;
	int total = (int)num;
	for(i = 0; i < total; i++) {
		counter++;
	}
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	// Assign default values.
	counter = 0;
	int num_threads = NUM_THREADS;
	int num_iterations = NUM_ITERATIONS;

	// Handles command-line arguments to change default values.	
	switch(argc) {
		case 1:
			break;
		case 3:
			if(argv[1][0] == '-' && argv[1][1] == 'x') {
				num_threads = atoi(argv[2]);
			}
			else if(argv[1][0] == '-' && argv[1][1] == 'y') {
				num_iterations = atoi(argv[2]);	
			}	
			break;
		case 5:
			if(argv[1][0] == '-' && argv[1][1] == 'x') {
				num_threads = atoi(argv[2]);
				num_iterations = atoi(argv[4]);
				
			}
			else if(argv[1][0] == '-' && argv[1][1] == 'y') {
				num_iterations = atoi(argv[2]);
				num_threads = atoi(argv[4]);
			}
			break;
		default:
			fprintf(stderr, "ERROR: Incorrect command-line arguments.\n");
			exit(EXIT_FAILURE);

	}

	printf("num_threads is %d.\n", num_threads);
	printf("num_iterations is %d.\n", num_iterations);

	pthread_t threads[num_threads];
	int status, i;

	for(i = 0; i < num_threads; i++) {
		status = pthread_create(&threads[i], NULL, increment, (void *)num_iterations);

		if(status != 0) {
			printf("Oops. pthread_create returned error code %d.\n", status);
		}
	}
	counter++;
	printf("Counter is %d.\n", counter);

#ifdef USE_PTHREAD_EXIT
    	pthread_exit(0);
#endif
}