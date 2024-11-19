#include <stdio.h> 

#include <stdlib.h> 

#include <unistd.h> 
 
int main(int argc, char *argv[]) { 

if (argc != 3) { 

printf("Por favor, ingresa dos números enteros como parámetros.\n"); 

return 1; 

} 

 

pid_t pid1 = fork(); 

 

if (pid1 < 0) { 

perror("Error al hacer fork"); 

return 1; 

} 

 

if (pid1 == 0) { 

printf("Intentando ejecutar ./punto15 con argumento %s\n", argv[1]); 

execlp("./punto15", "punto15", argv[1], NULL); 

perror("Error al ejecutar ./punto15"); 

exit(1); 

} 

 

pid_t pid2 = fork(); 

 

if (pid2 < 0) { 

perror("Error al hacer fork"); 

return 1; 

} 

 

if (pid2 == 0) { 

printf("Intentando ejecutar ./punto15 con argumento %s\n", argv[2]); 

execlp("./punto15", "punto15", argv[2], NULL); 

perror("Error al ejecutar ./punto15"); 

exit(1); 

} 

 

int status1, status2; 

waitpid(pid1, &status1, 0); 

printf("Hijo con PID %d terminó con estado %d\n", pid1, WEXITSTATUS(status1)); 

 

waitpid(pid2, &status2, 0); 

printf("Hijo con PID %d terminó con estado %d\n", pid2, WEXITSTATUS(status2)); 

 

printf("Ambos procesos hijos han terminado. Proceso padre finaliza ahora.\n"); 

return 0; 

} 