#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    pid_t nuevo;
    int n = 3;
    int num;

    for (num = 1; num <= n; num++){
        nuevo = fork();

        if ((num == n) && (nuevo == 0)) {
            execlp("ls", "ls", "-l", NULL);
            exit(EXIT_FAILURE);
        }
    }
    for (num = 1; num <= n; num++) {
        wait(NULL);
    }

    sleep(2);
    return 0;
}