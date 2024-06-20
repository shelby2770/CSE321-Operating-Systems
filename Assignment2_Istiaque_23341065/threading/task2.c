#include <stdio.h>
#include <pthread.h>

void *func(void *arg)
{
    int *id = (int *)arg;
    for (int i = 0; i < 5; ++i)
    {
        if (*id == 1)
        {
            printf("Thread %d prints %d\n", *id-1, i + 1);
        }
        else if (*id == 2)
        {
            printf("Thread %d prints %d\n", *id-1, i + 6);
        }
        else if (*id == 3)
        {
            printf("Thread %d prints %d\n", *id-1, i + 11);
        }
        else if (*id == 4)
        {
            printf("Thread %d prints %d\n", *id-1, i + 16);
        }
        else if (*id == 5)
        {
            printf("Thread %d prints %d\n", *id-1, i + 21);
        }
    }
}

signed main()
{
    pthread_t thread_id[5];
    int *id;
    for (int i = 0; i < 5; ++i)
    {
        id = (int *)malloc(sizeof(int));
        *id = i+1;
        pthread_create(&thread_id[i], NULL, func, id);
        pthread_join(thread_id[i], NULL);
    }
}