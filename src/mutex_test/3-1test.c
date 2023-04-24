#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;

void *lock_mutex(void *arg)
{
    int *mutex_locked = (int *)arg;
    pthread_mutex_lock(&mutex);
    printf("Mutex locked\n");
    *mutex_locked = 1;
    pthread_mutex_unlock(&mutex);
    printf("Mutex unlocked\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[2];
    int mutex_locked = 0;

    // mutexを初期化する
    pthread_mutex_init(&mutex, NULL);

    // スレッドを生成してmutexをロックする
    pthread_create(&threads[0], NULL, lock_mutex, (void *)&mutex_locked);
    pthread_create(&threads[1], NULL, lock_mutex, (void *)&mutex_locked);

    // スレッドの終了を待つ
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    // mutexを破棄する
    pthread_mutex_destroy(&mutex);

    return 0;
}
