#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	pid_t pid = fork();
	if (pid == 0) {
		printf("Child process is terminating\n");
	}
	else {
		wait(NULL); //Waits until the child process is complete
		printf("Parent process finished\n");
	}
	return 0;
}


