#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t process_id; //Variable to store process ID
    char *command_args[] = {"ls", "-l", NULL}; //Arguements for the command
    //Create a new process
    process_id = fork();
    if (process_id < 0) {
        //If fork() fails, print an error message
        printf("Fork failed\n");
        return -1;
    }
    else if (process_id == 0) {
        //This block is executed by the child process
        printf("Child process (PID: %d) executing 'ls -l' command...\n", getpid());
        //Execute the 'ls -l' command using execv()
        execv("/bin/ls", command_args);
        //If execv() fails, print an error message
        printf("execv failed\n");
        exit(-1); //Exit the child process with an error status
    }
    else {
        //This block is executed by parent process
        wait(NULL); //Wait for the child process to finish
        //Print a message indicating the child process has finished
        printf("Parent process (PID %d): Child Process has finished.\n", getpid());
    }
    return 0;
}
