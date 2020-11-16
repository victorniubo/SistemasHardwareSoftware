#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int count = 0;
void sig_handler(int num) {
    printf("Chamou Ctrl+C - count %d\n", count);
    count++;
    if (count > 1) {
        struct sigaction sa;
        sa.sa_handler = SIG_DFL;
        sa.sa_flags = 0;
        sigemptyset(&sa.sa_mask);

        sigaction(SIGINT, &sa, NULL);
    }
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sig_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGINT, &sa, NULL);
    
    printf("Meu pid: %d\n", getpid());

    while(1) {
        sleep(1);
    }
    return 0;
}
