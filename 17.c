#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <time.h> 

 

int main(int argc, char *argv[]) { 

if (argc < 2) { 

fprintf(stderr, "Uso: %s comando [argumentos...]\n", argv[0]); 

return 1; 

} 

 

time_t inicio, fin; 

inicio = time(NULL); 

 

pid_t pid = fork(); 

 

if (pid < 0) { 

perror("Error al hacer fork"); 

return 1; 

} 

 

if (pid == 0) { 

execvp(argv[1], &argv[1]); 

perror("Error al ejecutar el comando");  

exit(1); 

} 

 

int status; 

waitpid(pid, &status, 0); 

 

fin = time(NULL); 

 

printf("El comando '%s' tardó aproximadamente %ld segundos en ejecutarse.\n", 

argv[1], (long)(fin - inicio)); 

 

if (WIFEXITED(status)) { 

printf("El comando terminó con código de salida %d.\n", WEXITSTATUS(status)); 

} else { 

printf("El comando terminó de forma rara.\n"); 

} 

 

return 0; 

} 