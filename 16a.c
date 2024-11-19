#include <stdio.h> 

#include <stdlib.h> 

#include <unistd.h> 

 

int main(int argc, char *argv[]) { 

if (argc < 2) { 

fprintf(stderr, "Uso: %s num1 num2 ... numN\n", argv[0]); 

return 1; 

} 

 

pid_t pid; 

int i; 

 

printf("Creando procesos para calcular factoriales...\n"); 

 

for (i = 1; i < argc; i++) { 

pid = fork(); 

 

if (pid < 0) { 

perror("Error al crear un proceso hijo"); 

return 1; 

} 

 

if (pid == 0) { 

char *args[] = {"./punto15", argv[i], NULL}; 

execvp(args[0], args); 

perror("Error al ejecutar punto15"); 

exit(1); } 

} 

 

int status; 

pid_t finished_pid; 

 

for (i = 1; i < argc; i++) { 

finished_pid = wait(&status);  

 

 

if (finished_pid > 0) { 

printf("Proceso hijo con PID %d ha terminado.\n", finished_pid); 

} 

 

if (WIFEXITED(status)) { 

printf("Código de salida: %d\n", WEXITSTATUS(status)); 

} else { 

printf("El proceso hijo terminó de forma anómala.\n"); 

} 

} 

 

printf("Todos los procesos hijos han terminado.\n"); 

return 0; 

} 