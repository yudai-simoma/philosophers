#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

void *increment_counter(void *arg)
{
    int *counter = (int *)arg;
    for (int i = 0; i < 100000; i++) {
        *counter = *counter + 1;
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int counter = 0;

    // スレッドを生成してカウンターをインクリメントする
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment_counter, (void *)&counter);
    }

    // スレッドの終了を待つ
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Counter value: %d\n", counter);

    return 0;
}
