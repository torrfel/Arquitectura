#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>


void *factorial(void *dato) {
    long long int resultado = 1;
    int num, n = strtol((char *) dato, NULL, 10); 

    for (num = 2; num <= n; num++) {
        resultado = resultado * num;
        printf("Factorial de %d, resultado parcial %lld\n", n, resultado);
        sleep(random() % 3);
    }

    printf("El factorial de %d es %lld\n", n, resultado);

    pthread_exit((void *) dato); 
}

int main(int argc, char *argv[]) {
    

    int num_hilos = argc - 1; 
    pthread_t hilos[num_hilos];
    void *resultado;          

    srandom(time(NULL)); 

  
    for (int i = 0; i < num_hilos; i++) {
        if (pthread_create(&hilos[i], NULL, factorial, (void *) argv[i + 1])) {
            fprintf(stderr, "Error creando el hilo %d\n", i);
            return 1;
        }
    }

   
    for (int i = 0; i < num_hilos; i++) {
        if (pthread_join(hilos[i], &resultado) == 0) {
            printf("El hilo que calculó el factorial de %s ha finalizado.\n", (char *) resultado);
        } else {
            fprintf(stderr, "Error esperando el hilo %d\n", i);
        }
    }

    printf("Todos los hilos han terminado.\n");
    return 0;
}
