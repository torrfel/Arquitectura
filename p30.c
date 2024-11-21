#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>  

#define MAXLON 1000


typedef struct {
    char *nombre;
    int cont;  
} Parametros;


void *cuenta(void *arg) {
    int pos, leidos;
    char cadena[MAXLON];
    int fd;
    Parametros *param = (Parametros *)arg;

    fd = open(param->nombre, O_RDONLY);
    

    while ((leidos = read(fd, cadena, MAXLON)) != 0) {
        for (pos = 0; pos < leidos; pos++) {
            if (cadena[pos] == 'a' || cadena[pos] == 'A') {
                param->cont++;
            }
        }
    }

    close(fd);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

    pthread_t *hilos = malloc((argc - 1) * sizeof(pthread_t)); 
    Parametros *parametros = malloc((argc - 1) * sizeof(Parametros));

    for (int i = 1; i < argc; i++) {
        parametros[i - 1].nombre = argv[i];
        parametros[i - 1].cont = 0;

        
    }

    for (int i = 0; i < argc - 1; i++) {
        pthread_join(hilos[i], NULL);
    }

    for (int i = 0; i < argc - 1; i++) {
        printf("Fichero %s: %d caracteres 'a' o 'A' encontrados\n", parametros[i].nombre, parametros[i].cont);
    }

    free(hilos);
    free(parametros);

    return 0;
}
