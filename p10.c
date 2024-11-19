#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() { 

    time_t inicio = 0, fin = 0; 

    inicio = time(NULL); 

    if (fork() != 0) {  
        wait(NULL);  
        fin = time(NULL);  
        printf("Tiempo empleado: %ld segundos\n", fin - inicio); 
    } 
    else
        (execlp("prueba.exe", "prueba.exe", NULL) == -1); 
  
    return 0; 
} 