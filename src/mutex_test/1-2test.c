#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

pthread_mutex_t mutex;
int counter = 0;

void *increment_counter(void *arg)
{
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];

    // mutexの初期化
    pthread_mutex_init(&mutex, NULL);

    // スレッドを生成してカウンターをインクリメントする
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment_counter, NULL);
    }

    // スレッドの終了を待つ
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Counter value: %d\n", counter);

    pthread_mutex_destroy(&mutex);

    return 0;
}
