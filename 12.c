#include <sys/types.h> 

#include <sys/wait.h> 

#include <unistd.h> 

#include <stdio.h> 

#include <stdlib.h> 

#include <time.h> 

 

int main(int argc, char *argv[]) { 

pid_t kcalc, xload, fin; 

time_t inicio, fin_tiempo; 

int n; 

 

inicio = time(NULL); 

 

kcalc = fork(); 

if (kcalc == 0) { 

execlp("kcalc", "kcalc", NULL); 

perror("No hemos logrado encontrar kcalc"); 

exit(1); 

} 

 

xload = fork(); 

if (xload == 0) { 

execlp("xload", "xload", NULL); 

perror("No hemos logrado encontrar xload"); 

exit(1); 

} 

 

for (n = 0; n < 2; n++) { 

fin = wait(NULL); 

if (fin == kcalc) { 

printf("kcalc terminó\n"); 

} else if (fin == xload) { 

printf("xload terminó\n"); 

} 

} 

 

fin_tiempo = time(NULL); 

 

printf("Tiempo total empleado: %ld segundos\n", fin_tiempo - inicio); 

 

return 0; 

} 