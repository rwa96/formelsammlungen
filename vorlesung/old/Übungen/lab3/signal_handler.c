#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void signal_handler(int sig){
	char* sig_name = sig == SIGUSR1 ? "SIGUSR1": "SIGUSR2";
	printf("Signal %s received!\r\n", sig_name);
}

int main(void) {
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);

	while(1)
		sleep(1);

	return EXIT_SUCCESS;
}
