#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(void) {
	int fd[2], nbytes;
	pid_t childpid;
	char string[] = "Hello world!\n";
	char readbuffer[80];

	if (pipe(fd) == -1) {
		perror("pipe failed");
		exit(1);
	}

	if ((childpid == fork()) == -1) {
		perror("fork failed");
		exit(1);
	}

	if (childpid == 0) {
		close(fd[0]);
		write(fd[1], string, strlen(string) + 1);
		printf("childpid is 0\n");
		close(fd[1]);
		exit(0);
	}

	else {
		close(fd[1]);
		nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
		printf("Receieved string: %s", readbuffer);
		close(fd[0]);
	}

	return 0;

}

/*
In this code, a parent and child process is created with fork() where the
child writes the message "Hello world!" to the pipe and the parent reads
it and prints it. The program ensures proper usage by closing unused pipe
ends in each process.
*/
