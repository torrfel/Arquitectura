#include <stdio.h> 

#include <stdlib.h> 

#include <unistd.h> 

#include <sys/wait.h> 

  

int main(int argc, char *argv[]) { 

    if (argc != 3) { 

        printf("Por favor, ingresa dos números enteros como parámetros.\n"); 

        return 1; 

    } 

  

    // Convertir los parámetros de entrada a enteros 

    int num1 = atoi(argv[1]); 

    int num2 = atoi(argv[2]); 

  

    // Crear el primer proceso hijo para calcular el factorial de num1 

    pid_t pid1 = fork(); 

  

    if (pid1 < 0) { 

        perror("Error al hacer fork"); 

        return 1; 

    } 

  

    if (pid1 == 0) { 

        // Proceso hijo 1: calcular el factorial de num1 

        execlp("./punto15", "punto15", argv[1], NULL); 

        perror("Error al ejecutar punto15"); 

        exit(1); 

    } 

  

    // Crear el segundo proceso hijo para calcular el factorial de num2 

    pid_t pid2 = fork(); 

  

    if (pid2 < 0) { 

        perror("Error al hacer fork"); 

        return 1; 

    } 

  

    if (pid2 == 0) { 

        // Proceso hijo 2: calcular el factorial de num2 

        execlp("./punto15", "punto15", argv[2], NULL); 

        perror("Error al ejecutar punto15"); 

        exit(1); 

    } 

  

    // Proceso padre: esperar a que ambos hijos terminen 

    int status; 

    waitpid(pid1, &status, 0);  // Esperar al primer hijo 

    waitpid(pid2, &status, 0);  // Esperar al segundo hijo 

  

    printf("Ambos procesos hijos han terminado.\n"); 

    return 0; 

} 