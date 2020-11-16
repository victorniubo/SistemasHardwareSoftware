#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#include <stdio.h>
#include <string.h>

int main() {
    pid_t filho;

    filho = fork();
    if (filho == 0) {
        printf("pid: %d\n", getpid());
        printf("terminei!\n");
        return 2;
    }
    sleep(10);
    int st;
    if (waitpid(filho, &st, WNOHANG) == 0) {
        kill(filho, SIGKILL);
        wait(&st);
    }     
    
    if (WIFSIGNALED(st)) {
        printf("sinal: %s\n", strsignal(WTERMSIG(st)));
    }

    return 0;
}
