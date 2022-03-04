// Author: Trever Hall
// Date: 3/3/2022
// Description: Pthread Locks

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_THREADS 4
#define NUM_ITERATIONS 10000
pthread_mutex_t mutex;
// Global variable that the threads increment.
static int counter = 0;



// ========================================================================= //
// HELPER FUNCTIONS
// Increments the counter *num times. Used by the threads.
void *increment(void *num)
{
	/*This function increments the global counter by num.*/
	int i;
	int total = (int)num;
	for(i = 0; i < total; i++) {
		pthread_mutex_lock(&mutex);
		counter++;
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}



// ========================================================================= //
// MAIN FUNCTION
// Acts as the outer-most parent thread.
int main(int argc, char *argv[])
{
	// Handles command-line arguments.	
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


	// Assign default values.
	int num_threads = NUM_THREADS;
	int num_iterations = NUM_ITERATIONS;
	// Initialize threads and variables used. 
	pthread_mutex_init(&mutex, NULL);
	pthread_t threads[num_threads];
	int status, i;


	// Create each thread.
	for(i = 0; i < num_threads; i++) {
		status = pthread_create(&threads[i], NULL, increment, (void *)num_iterations);
		if(status != 0) {
			printf("Oops. pthread_create returned error code %d.\n", status);
		}
	}
	// Wait for each thread to return.
	for(i = 0; i < num_threads; i++) {
		pthread_join(threads[i], NULL);
	}



	printf("Counter is %d.\n", counter);

	// Release pthread_mutex from memory. 
	pthread_mutex_destroy(&mutex);
	// Waits for all threads to complete, then exits the program.
	#ifdef USE_PTHREAD_EXIT
    	pthread_exit(0);
	#endif
}