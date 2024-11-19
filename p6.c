#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define L1 2
#define L2 3
int main (int argc, char *argv[]) {
    int cont1, cont2;
    pid_t pid;
    printf("%d\n", getpid());
    for (cont2= 0; cont2< L2; cont2++) {
        for (cont1= 0; cont1< L1; cont1++) {
            pid= fork();
            if (pid== 0)
                break;
        }
            if (pid!= 0)
                break;
    }

    printf("Soy el proceso %d y mi padre es %d. cont1: %d cont2: %d\n", getpid(), getppid(), cont1, cont2);
    
    if (pid!= 0) 
        for (int i = 0; i < L1; i++) 
            printf("Fin del proceso %d\n", wait(NULL));
    

    return 0;
}