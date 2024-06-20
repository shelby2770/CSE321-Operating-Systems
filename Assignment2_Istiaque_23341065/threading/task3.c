#include <stdio.h>
#include <pthread.h>

const int N=100;
void *count_ascii(void *arg)
{
    char *name = (char *)arg;
    int i = 0, sum = 0;
    int *result = (int *)malloc(sizeof(int));
    while (name[i] != '\0')
    {
        sum += name[i];
        i++;
    }
    *result = sum;
    return result;
}


signed main()
{
    pthread_t t1, t2, t3;
    char name1[N],name2[N],name3[N];
    scanf("%s", name1);
    scanf("%s", name2);
    scanf("%s", name3);
    int *res1, *res2, *res3;

    pthread_create(&t1, NULL, count_ascii, (void *)name1);
    pthread_join(t1, (void **)&res1);
    pthread_create(&t2, NULL, count_ascii, (void *)name2);
    pthread_join(t2, (void **)&res2);
    pthread_create(&t3, NULL, count_ascii, (void *)name3);
    pthread_join(t3, (void **)&res3);

    if (*res1 == *res2 && *res1 == *res3)
    {
        printf("Youreka\n");
    }
    else if (*res1 == *res2 || *res1 == *res3 || *res2 == *res3)
    {
        printf("Miracle\n");
    }
    else
    {
        printf("Hasta la vista\n");
    }
}