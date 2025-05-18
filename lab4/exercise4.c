#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(void) {
	int fd[2];
	pid_t childpid;
	char message[] = "Hello from parent";
	char readbuffer[50];

	if (pipe(fd) == -1) {
		perror("Pipe failed");
		exit(1);
	}

	childpid = fork();
	if (childpid == -1) {
		perror("Fork failed");
		exit(1);
	}
	if (childpid == 0) {
		close(fd[1]);
		read(fd[0], readbuffer, sizeof(setbuffer));
		printf("Child received: %s\n", readbuffer);
		close(fd[0]);
	}
	else {
		close(fd[0]);
		write(fd[1], message, strlen(message) + 1);
		close(fd[1]);
	}
	return 0;
}

/*
In this code the following changes were made:
- Replacing buffer with readbuffer
- Adding +1 to strlen(messages) so null terminator is passed \0 making %s
print properly.
- pipe(fd) was added so that silent failure was avoided
- closing the pipe in the child pro
*/
