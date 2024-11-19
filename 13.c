#include <stdio.h> 

#include <stdlib.h> 

#include <unistd.h> 

#include <sys/types.h> 

#include <sys/wait.h> 

#include <time.h> 

 

void escribir_cadena(char *cadena) { 

for (int i = 0; cadena[i] != '\0'; i++) { 

printf("%c", cadena[i]); 

fflush(stdout); 

usleep((rand() % 300 + 200) * 1000); 

} 

printf("\n"); 

} 

 

int main() { 

char cadena1[100], cadena2[100]; 

pid_t pid; 

 

printf("Introduce la primera cadena: "); 

fgets(cadena1, sizeof(cadena1), stdin); 

cadena1[strcspn(cadena1, "\n")] = '\0';  

 

printf("Introduce la segunda cadena: "); 

fgets(cadena2, sizeof(cadena2), stdin); 

cadena2[strcspn(cadena2, "\n")] = '\0';a 

 

pid = fork(); 

 

if (pid == 0) { 

srand(time(NULL) ^ getpid()); 

escribir_cadena(cadena2); 

exit(0); 

} else if (pid > 0) { 

wait(NULL); 

 

srand(time(NULL)); 

escribir_cadena(cadena1); 

} else { 

perror("Error al crear el proceso"); 

return 1; 

} 

 

return 0; 

} 
