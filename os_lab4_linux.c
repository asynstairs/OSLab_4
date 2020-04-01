#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main ( void ){
    pid_t p;
    int exitcode;
    printf("Original PID = %d\n", p);

    switch ( p = fork() ) {
        case 0: {
            printf("Child Process. PID = %d, PPID = %d\n", getpid(), getppid());
            system("bin/ls -la /tmp");
            exit(5);
        }
        case -1: {
            printf("Error\n");
        }
        default: {
            printf("Parent Process. PID = %d, Child PID = %d\n", getpid(), p);
            wait(&exitcode);
            if ( WIFEXITED (exitcode) ){
                printf("exit() successful in child process.\n");
                printf("exitcode = %d\n", WEXITSTATUS(exitcode));
            }
        }
    }
}
