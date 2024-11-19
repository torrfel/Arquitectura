#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {

    int n = 3 ;
    pid_t pid, nuevo,npid;
    int cont1, cont2;

    printf("%d\n", getpid());


    for (cont1= 0; cont1<n; cont1++){
        pid = getpid();
        for (cont2= 0; cont2< cont1+2; cont2++){
            nuevo = fork();
            if (nuevo== 0) 
                break;
        }
        npid = getpid();
        if(npid == pid){
            break;
        }
    }
    printf("Soy el proceso %d y mi padre es %d\n", getpid(), getppid());
    sleep (2);
    return 0;
}