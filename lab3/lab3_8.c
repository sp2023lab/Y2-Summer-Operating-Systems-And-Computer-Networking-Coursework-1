#include <stdio.h>
#include <unistd.h>

int main() {
	/*Fork a child process*/
	fork();

	/*Fork another child process*/
	fork();

	/*and fork another*/
	fork();

	sleep(15); /* Pause for 15 seconds */

	return 0;
}
/*
3 forks so the process is 2^3 so 8 processes are running. So 7 newly created child
processes and 1 orignal (parent) process
*/
