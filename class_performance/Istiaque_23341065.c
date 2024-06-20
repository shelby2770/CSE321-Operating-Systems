#include <stdio.h>
#include <pthread.h>

int arr[5], max, min;
float avg;

void *max_ele(void *arg)
{
    max = arr[0];
    for (int i = 1; i < 5; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("Maximum element: %d\n", max);
    pthread_exit(0);
}

void *min_ele(void *arg)
{
    min = arr[0];
    for (int i = 1; i < 5; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("Minimum element: %d\n", min);
    pthread_exit(0);
}

void *avg_calc(void *arg)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += arr[i];
    }
    avg = (float)sum / 5;
    printf("Average: %f\n", avg);
    pthread_exit(0);
}

signed main()
{
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    pthread_t threads[3];
    pthread_create(&threads[0], 0, max_ele, 0);
    pthread_create(&threads[1], 0, min_ele, 0);
    pthread_create(&threads[2], 0, avg_calc, 0);

    for (int i = 0; i < 3; i++)
    {
        pthread_join(threads[i], 0);
    }
}