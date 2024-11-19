#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    pid_t nuevo;
    pid_t pid;
    int i , j=0;
    printf("%d\n", getpid());
    for (i= 0; i< 2; i++) {
        pid= getpid();
        for (j= 0; j< i+2; j++) {
            nuevo= fork();
            if (nuevo!= 0) {
                nuevo= fork();
                break;
            }
        }
        if (pid!= getpid())
            break;
    }
    printf("Soy el proceso de PID %d y mi padre tiene %d de PID. con i: %d j: %d\n", getpid(), getppid(),i,j); 

    sleep(2);
    return 0;
}