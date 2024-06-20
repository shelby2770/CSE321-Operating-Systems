#include <stdio.h>
#include <unistd.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

signed main(int argc, char *argv[])
{
    int n = argc - 1, arr[n];
    for (int i = 0; i < n; ++i)
        arr[i] = atoi(argv[i + 1]);

    pid_t pid = fork();
    if (!pid)
    {
        qsort(arr, n, sizeof(int), cmp);
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    else
    {
        wait(0);
        for (int i = 0; i < n; ++i)
            printf("%d is %s\n", arr[i], (arr[i] & 1 ? "Odd" : "Even"));
    }
}
