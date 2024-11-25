#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>

#define MAXLON 1000
#define K 100  

typedef struct {
    char *buffer;
    int start;
    int end;
    int *count;
    pthread_mutex_t *mutex;
} ThreadParams;

void *cuenta_espacios(void *arg) {
    ThreadParams *params = (ThreadParams *)arg;
    int local_count = 0;

    for (int i = params->start; i < params->end; i++) {
        if (params->buffer[i] == ' ') {
            local_count++;
        }
    }

    pthread_mutex_lock(params->mutex);
    *(params->count) += local_count;
    pthread_mutex_unlock(params->mutex);

    pthread_exit(NULL);
}

void procesa_fichero(const char *nombre) {
    int fd = open(nombre, O_RDONLY);
    if (fd < 0) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    char buffer[MAXLON];
    int total_spaces = 0, bytes_read;

    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);

    while ((bytes_read = read(fd, buffer, MAXLON)) > 0) {
        int num_hilos = (bytes_read + K - 1) / K; 
        pthread_t hilos[num_hilos];
        ThreadParams params[num_hilos];

        for (int i = 0; i < num_hilos; i++) {
            params[i].buffer = buffer;
            params[i].start = i * K;
            params[i].end = (i + 1) * K < bytes_read ? (i + 1) * K : bytes_read;
            params[i].count = &total_spaces;
            params[i].mutex = &mutex;

            pthread_create(&hilos[i], NULL, cuenta_espacios, &params[i]);
        }

        for (int i = 0; i < num_hilos; i++) {
            pthread_join(hilos[i], NULL);
        }
    }

    close(fd);
    pthread_mutex_destroy(&mutex);

    printf("Fichero %s: %d espacios encontrados\n", nombre, total_spaces);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <fichero1> <fichero2> ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("Error al crear el proceso");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            procesa_fichero(argv[i]);
            exit(EXIT_SUCCESS);
        }
    }

    for (int i = 1; i < argc; i++) {
        wait(NULL);
    }

    return 0;
}
