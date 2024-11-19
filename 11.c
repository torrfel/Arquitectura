 

#include <sys/types.h> 

#include <sys/wait.h> 

#include <unistd.h> 

#include <stdio.h> 

#include <stdlib.h> 

 

int main (int argc, char *argv[]) { 

pid_t kcalc, xload, fin; 

int n; 

 

kcalc = fork(); 

if(kcalc == 0){ 

execlp ("kcalc", "kcalc", NULL); 

printf("No hemos logrado encontrar kcalc\n"); 

exit(0); 

} 

xload=fork(); 

if(xload==0){ 

execlp ("xload", "xload", NULL); 

printf("No hemos logrado encontrar xload\n"); 

exit(0); 

} 

for(n=0;n<2;n++){ 

fin = wait(NULL); 

if(fin==kcalc){ 

printf("kcalc terminó"); 

} 

else 

printf("xload terminó"); 

} 

return 0; 

} 