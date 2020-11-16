#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int status = 0;

void operacao_lenta() {
    sleep(10);
}


void sigint_handler(int num) {
    status += 1;
    printf("Chamou Ctrl+C; status=%d\n", status);
    operacao_lenta();
    printf("SIGINT: Vou usar status agora! status=%d\n", status);
}

void sigterm_handler(int num) {
    status += 1;
    printf("Recebi SIGTERM; status=%d\n", status);
    operacao_lenta();
    printf("SIGTERM: Vou usar status agora! status=%d\n", status);
}

int main() {
    struct sigaction sint;
    sint.sa_handler = sigint_handler;
    sint.sa_flags = 0;
    sigemptyset(&sint.sa_mask);
    sigaction(SIGINT, &sint, NULL);

    struct sigaction sterm;
    sterm.sa_handler = sigterm_handler;
    sterm.sa_flags = 0;
    sigemptyset(&sterm.sa_mask);
    sigaction(SIGTERM, &sterm, NULL);


    printf("Meu pid: %d\n", getpid());

    while(1) {
        sleep(1);
    }
    return 0;
}
