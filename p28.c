#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <time.h>


void escribir_cadena(char *cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        printf("%c", cadena[i]);
        fflush(stdout);
        usleep((rand() % 300 + 200) * 1000);  
    }
    printf("\n");
}


void *escribir_hilo(void *arg) {
    char *cadena = (char *) arg;
    escribir_cadena(cadena);
    pthread_exit(NULL);  
}

int main() {
    char cadena1[100], cadena2[100];
    pthread_t hilo1, hilo2;

  
    printf("Introduce la primera cadena: ");
    fgets(cadena1, sizeof(cadena1), stdin);
    cadena1[strcspn(cadena1, "\n")] = '\0'; 

    printf("Introduce la segunda cadena: ");
    fgets(cadena2, sizeof(cadena2), stdin);
    cadena2[strcspn(cadena2, "\n")] = '\0';  
    
    srand(time(NULL));

    
    if (pthread_create(&hilo1, NULL, escribir_hilo, (void *)cadena1) != 0) {
        perror("Error al crear el primer hilo");
        return 1;
    }

    
    pthread_join(hilo1, NULL);

  
    if (pthread_create(&hilo2, NULL, escribir_hilo, (void *)cadena2) != 0) {
        perror("Error al crear el segundo hilo");
        return 1;
    }

   
    pthread_join(hilo2, NULL);

    printf("Los hilos han terminado.\n");

    return 0;
}
