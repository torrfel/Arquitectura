#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    int i;
    int prof, anch;
    int profundidad, anchura;

    printf("%d\n", getpid());

    if (argc!= 3) exit(0);

    profundidad= atoi(argv[1]);
    anchura= atoi(argv[2]); 

    for (prof= 0; prof< profundidad-1; prof++) 
        if (fork()!= 0) 
            break;

    for (anch= 0; anch< anchura-1; anch++) 
        if (fork()== 0) 
            break;
    

    printf("Soy el proceso %d y mi padre es %d\n", getpid(), getppid());
    sleep (2);
    return 0;
}