#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

struct soma_parcial_args {
    double *vetor;
    int start, end;
};

pthread_mutex_t mut;
double soma = 0;
void *soma_parcial(void *_arg) {
    struct soma_parcial_args *spa = _arg;
    double soma_parcial_var = 0;
    for (int i = spa->start; i < spa->end; i++) {
        soma_parcial_var += spa->vetor[i];
    }

    pthread_mutex_lock(&mut);
    soma += soma_parcial_var;
    pthread_mutex_unlock(&mut);

    return NULL;
}

int main(int argc, char *argv[]) {
    double *vetor = NULL;
    int n;
    scanf("%d", &n);

    vetor = malloc(sizeof(double) * n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &vetor[i]);
    }

    pthread_mutex_init(&mut, NULL);

    pthread_t tids[4];
    struct soma_parcial_args args[4];
    for (int i = 0; i < 4; i++) {
        int part_size = n/4;
        args[i] = (struct soma_parcial_args) {vetor, i * part_size, (i+1) * part_size };
        if (i == 3) {
            args[i].end = n;
        }
        pthread_create(&tids[i], NULL, soma_parcial, &args[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(tids[i], NULL);
    }

    printf("Paralela: %lf\n", soma);

    soma = 0;
    struct soma_parcial_args aa;
    aa.vetor = vetor;
    aa.start = 0;
    aa.end = n;
    soma_parcial(&aa);
    printf("Sequencial: %lf\n", soma);

    return 0;
}
