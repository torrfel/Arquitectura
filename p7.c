#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]) {
    int i, j;
    pid_t pid, nuevo, nuevo1;
    time_t ini, fin;

    ini = time(NULL);

    for (i = 0; i < 2; i++) {
        pid = getpid();
        for (j = 0; j < i + 2; j++) {
            nuevo = fork();
            if (nuevo == 0) {
                nuevo1 = fork();
                if (nuevo1 == 0) {
                    execlp("xload", "xload", NULL);
                    perror("execlp xload");
                    exit(EXIT_FAILURE);
                } else {
                    wait(NULL);
                    printf("Tiempo de ejecución de xload: %ld segundos\n", time(NULL) - ini);
                    exit(0);
                }
            }
        }
        if (pid != getpid()) {
            execlp("kcalc", "kcalc", NULL);
            perror("execlp kcalc");
            exit(EXIT_FAILURE);
        }
    }

    while (wait(NULL) > 0);

    fin = time(NULL);

    printf("Tiempo total: %ld segundos\n", fin - ini);

    return 0;
}