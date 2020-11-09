#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    double soma = 0;
    for (int i = 1; i < argc; i++) {
        soma += atof(argv[i]);
    }
    printf("%f\n", soma);

    return 0;
}
