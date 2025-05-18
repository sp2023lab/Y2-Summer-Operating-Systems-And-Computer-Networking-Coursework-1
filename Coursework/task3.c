#include <stdio.h>
#include <unistd.h>
int main() {
    printf("Parent process: PID = %d\n", getpid());
    fork();
    if (fork()) {
        fork();
    }
    else {
        fork();
        fork();
    }
    printf("Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    return 0;
}
