#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int num, ret = 0, status;
    char num_str[100];
    while (ret != -1) {
        scanf("%d", &num);
        if (fork() == 0) {
            sprintf(num_str, "%d", num);
            execvp("./eh_par", (char *[]) {"eh_par", num_str, NULL});
        }
        wait(&status);
        if (WIFEXITED(status)) {
            ret = (char) WEXITSTATUS(status);
            if (ret == 1) printf("Eh par\n");
            else if (ret == 0) printf("Nao eh par\n");
        } else {
            break;
        }

        
    }
    return 0;
}