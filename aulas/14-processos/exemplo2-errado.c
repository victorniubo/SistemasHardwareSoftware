#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t filho;

    filho = fork();

    if (filho == 0) {
        printf("Acabei filho: %d\n", getpid());
        sleep(3);
        exit(-2);
    } else {
        int st;
        pid_t filho_que_acabou = wait(&st);
        printf("Filho acabou: %d\n", filho_que_acabou);
        if (WIFEXITED(st)) { // acabou normalmente -> exit ou fim do main
            printf("Valor de retorno: %d\n", (char) WEXITSTATUS(st));
        }
        if (WIFSIGNALED(st)) { // recebeu um sinal de erro?
            printf("Código do erro: %d\n", WTERMSIG(st));
        }
    }
    return 0;
}
