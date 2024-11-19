#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {  
    int num;  
    pid_t pid; 
    printf("%d\n", getpid());
    for (num = 0; num < 3; num++) {  
        pid = fork(); 
        
        printf("Soy el proceso de PID %d y mi padre tiene %d de PID.\n",  
               getpid(), getppid());  

        if (pid != 0) 
            break; 

        srandom(getpid());  
        sleep(random() % 3); 
    }  

    if (pid != 0) // Solo el padre llegará aquí  
        printf("Fin del proceso de PID %d.\n", wait(NULL)); 

    return 0;  
}  