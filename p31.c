#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h> 
#include <string.h>  

#define MAXLON 1000

typedef struct {
    char *nombre;
    int resultado;
} Parametros;

void *cuenta(void *arg) {
    int pos, leidos;
    char cadena[MAXLON];
    int fd;

    Parametros *param = (Parametros *)arg;
    param->resultado = 0; 

    
    fd = open(param->nombre, O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el fichero");
        pthread_exit(NULL);
    }

   
    while ((leidos = read(fd, cadena, MAXLON)) > 0) {
        for (pos = 0; pos < leidos; pos++) {
            if (cadena[pos] == 'a' || cadena[pos] == 'A') {
                param->resultado++;
            }
        }
    }

    close(fd);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Indica al menos un fichero como parámetro.\n");
        exit(0);
    }

    pthread_t *hilos = malloc((argc - 1) * sizeof(pthread_t));
    Parametros *parametros = malloc((argc - 1) * sizeof(Parametros)); 

    
    for (int i = 1; i < argc; i++) {
        parametros[i - 1].nombre = argv[i];
        parametros[i - 1].resultado = 0;

        if (pthread_create(&hilos[i - 1], NULL, cuenta, &parametros[i - 1]) != 0) {
            perror("Error al crear el hilo");
            free(hilos);
            free(parametros);
            exit(1);
        }
    }

 
    for (int i = 0; i < argc - 1; i++) {
        pthread_join(hilos[i], NULL);
    }


    for (int i = 0; i < argc - 1; i++) {
        printf("Fichero %s: %d caracteres 'a' o 'A' encontrados\n",
               parametros[i].nombre, parametros[i].resultado);
    }

    // Liberar memoria
    free(hilos);
    free(parametros);

    return 0;
}
