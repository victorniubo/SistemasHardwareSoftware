
#include <pthread.h>
#include <stdio.h>

void *minha_thread(void *arg) {
    printf("Hello thread!\n");
    return NULL;
}


void *minha_thread2(void *arg) {
    printf("Hello thread 2!\n");
    return NULL;
}


void *minha_thread3(void *arg) {
    printf("Hello thread 3!\n");
    return NULL;
}


void *minha_thread4(void *arg) {
    printf("Hello thread 4!\n");
    return NULL;
}


int main() {
    pthread_t tid[4];
    
    pthread_create(&tid[0], NULL, minha_thread, NULL);
    pthread_create(&tid[1], NULL, minha_thread2, NULL);
    pthread_create(&tid[2], NULL, minha_thread3, NULL);
    pthread_create(&tid[3], NULL, minha_thread4, NULL);
    

    printf("Hello main\n");  

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    pthread_join(tid[3], NULL);
    return 0;
}
