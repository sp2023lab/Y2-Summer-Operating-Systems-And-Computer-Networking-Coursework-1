/*Task is to fix the creation of an orphan process (DONE)*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int pid = fork();
	if (pid > 0) { //Parent process
		printf("Parent process exiting...\n");
		wait(NULL);
		printf("Child process is finished, Parent exiting...\n");
	}
	else if (pid == 0) { //Child process
		sleep(5); //Delay to ensure parent exits first
		printf("Child process running, adopted by init. My PID %d, Parent PID: %d\n", getpid(), getppid());
	}
	else {
		printf("Fork failed!\n");
	}
	return 0;
}
