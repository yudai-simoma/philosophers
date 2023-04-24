#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2
#define ARRAY_SIZE 10

int array[ARRAY_SIZE];
pthread_mutex_t mutex;

void *increment_array(void *arg)
{
    int id = *(int *)arg;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        // mutexを使用して競合状態を防止する
        pthread_mutex_lock(&mutex);
        array[i] += id;
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // 配列を初期化する
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = 0;
    }

    // mutexを初期化する
    pthread_mutex_init(&mutex, NULL);

    // スレッドを生成して配列をインクリメントする
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, increment_array, (void *)&thread_ids[i]);
    }

    // スレッドの終了を待つ
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // mutexを破棄する
    pthread_mutex_destroy(&mutex);

    // 結果を出力する
    printf("Array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
