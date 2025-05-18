/*Compile and run program and observe creation of zombie (DONE)*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int pid = fork();
	if (pid > 0) { //Parent process
		printf("Parent process running. PID:  %d\n", getpid());
		sleep(10); //Parent sleeps, child exits before parent calls wait()
	}
	else if (pid == 0) { //Child process
		printf("Child process exiting. PID:  %d\n", getpid());
		exit(0); //Child exits but parent hasn't collected status
	}
	else {
		printf("Fork failed!\n");
	}
	return 0;
}

/*
The zombie is created by the parent sleeping. The child becomes a zombie as the
parent is sleeping when child process exits.
*/
