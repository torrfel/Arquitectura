#include <stdio.h>  

#include <string.h>  

#include <stdbool.h> 

#include <unistd.h> 

#include <sys/wait.h> 

#include <stdlib.h> 

#include <sys/types.h> 

 

int main (int argc, char *argv[]) {  

    bool fin= false;  

    char nombre_prog[50], esperar[5]; 

    pid_t pid; 

 

    while (!fin) { 

        printf ("Programa: "); scanf (" %s", nombre_prog); 

        if (strcmp(nombre_prog, "salir")!=0) { 

            printf ("Esperar? "); scanf (" %s", esperar); 

 

        pid = fork(); 

        if(pid!=0){ 

            if(strcmp(esperar, "si")==0) 

                while(pid!=wait(NULL)); 

            else 

                printf("PID hijo: %d\n", pid); 

        }else{ 

            if(execlp(nombre_prog, nombre_prog, NULL)==-1) 

                printf("No ha sido posible ejecutarlo. PATH: %s\n",          			getenv("PATH")); 

            exit(0); 

        } 

    } 

    else 

        fin= true; 

    } 

    return 0; 

} 