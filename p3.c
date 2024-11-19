#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t nuevo;
    int num;
    printf("%d\n", getpid());
    for(num=0; num<2; num++){
        nuevo = fork(); /* 1 */
        if (nuevo == 0)
            break;
    }
    nuevo = fork(); /* 2 */
    nuevo = fork(); /* 3 */
    printf("Soy el proceso (%d) %d y mi padre es (%d) %d\n",num,getpid(), num,getppid());
    sleep(2);
    return 0;
}