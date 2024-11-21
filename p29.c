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
    
    pthread_t hilo;
    Parametros parametros;
    parametros.nombre = argv[1];
    parametros.cont = 0;

    if (pthread_create(&hilo, NULL, cuenta, (void *)&parametros) != 0) {
        perror("Error al crear el hilo");
        exit(1);
    }

   
    pthread_join(hilo, NULL);


    printf("Fichero %s: %d caracteres 'a' o 'A' encontrados\n", parametros.nombre, parametros.cont);

    return 0;
}
