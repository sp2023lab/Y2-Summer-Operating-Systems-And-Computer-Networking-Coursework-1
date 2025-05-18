#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h> //Include this for wait()
int main() {
	int ret = fork();
	if (ret == 0) {
		/*This is the child process*/
		printf("The child process ID is %d\n", getpid());
		printf("The child parent process ID is %d\n", getppid());
	}
	else {
		/*This is the parent process*/
		wait(NULL); //Parent waits for child to finish
		printf("The parent process ID is %d\n", getpid());
		printf("The parent parent process ID is %d\n", getppid());
	}
	sleep(2);
	return 0;
}
