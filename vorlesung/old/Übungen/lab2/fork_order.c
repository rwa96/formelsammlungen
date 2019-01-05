#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PRINT_COUNT 200
#define PRC_COUNT 3
#define TRUE 1
#define FALSE 0


void child(int pid){
	int count;
	for(count = 0; count < PRINT_COUNT; count++){
		printf("Kind mit PID=%d\r\n", pid);
	}
}

void parent(int* children){
	int count;
	for(count = 0; count < PRINT_COUNT; count++){
		printf("%d, %d, %d\r\n", children[0], children[1], children[2]);
	}
}

int main(void) {
	int children[] = {0, 0, 0};
	char is_parent = TRUE;

	int count;
	for(count = 0; count < PRC_COUNT && is_parent; count++){
		children[count] = fork();
		if(children[count] == 0){
			is_parent = FALSE;
			break;
		}else if(children[count] == -1){
			fprintf(stderr, "Process could not be created!\r\n");
			return EXIT_FAILURE;
		}
	}

	if(is_parent){
		parent(children);
	}else{
		child(getpid());
	}

	return EXIT_SUCCESS;
}
