#include <stdio.h>
#include <pthread.h>

const int N = 5;
void *func(void *arg)
{
    int thread_num = *((int *)arg);
    printf("thread-%d running\n", thread_num);
    printf("thread-%d closed\n", thread_num);
}

signed main()
{
    pthread_t threads[N];
    int thread_nums[N];

    for (int i = 0; i < N; ++i)
    {
        thread_nums[i] = i + 1;
        pthread_create(&threads[i], NULL, func, (void *)&thread_nums[i]);
        pthread_join(threads[i], NULL);
    }
}