#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <stdio.h>


#define NUM_THREADS 10
#define MAX_ITERATIONS 1000


int shared_counter = 0;


void* task(void* value_pointer){
	int value = *((int*) value_pointer);

	int count;
	for(count = 0; count < MAX_ITERATIONS; count++){
		shared_counter += value;
	}

	return NULL;
}


int main(void) {
	pthread_attr_t attr;
	if(	pthread_attr_init(&attr) ||
		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE)){

		fprintf(stderr, "error: could't create thread or mutex attributes!\r\n");
		return EXIT_FAILURE;
	}

	pthread_t threads[NUM_THREADS];
	pthread_t new_thread;
	int add_value = 1;
	int sub_value = -1;

	int index;
	for(index = 0; index < NUM_THREADS; index++){
		if(pthread_create(	&new_thread,
							&attr,
							&task,
							(void*)(index < NUM_THREADS/2 ? &add_value : &sub_value))){

			fprintf(stderr, "error when trying to create a thread!\r\n");
			return EXIT_FAILURE;
		}else{
			threads[index] = new_thread;
		}
	}

	for(index = 0; index < NUM_THREADS; index++){
		if(pthread_join(threads[index], NULL)){
			fprintf(stderr, "error when trying to join thread 0x%lX!\r\n", threads[index]);
			return EXIT_FAILURE;
		}else{
			printf("Thread No. 0x%lX joined\r\n", threads[index]);
		}
	}

	printf("Counter value: %d\r\n", shared_counter);

	return EXIT_SUCCESS;
}
