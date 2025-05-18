#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    int pfds[2];
    pipe(pfds); // Create a pipe
    if (!fork()) { // Child process
        close(1); // Close stdout
        dup(pfds[1]); // Redirect stdout to pipe write end
        close(pfds[0]); // Close read end of the pipe
        execlp("/usr/bin/cat", "cat", "file.txt", NULL); // Execute 'cat file.txt'
    }
    else { // Parent process
        close(0); // Close stdin
        dup(pfds[0]); // Redirect stdin to pipe read end
        close(pfds[1]); // Close write end of the pipe
        printf("PATH: %s\n", getenv("PATH"));
        execlp("/usr/bin/grep", "grep", "pattern", NULL); // Execute 'grep pattern'
    }
    return 0;
}
