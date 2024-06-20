#include <stdio.h>
#include <unistd.h>

signed main()
{
    pid_t pid1, pid2, pid3, pid4, pid5;
    pid1 = getpid();
    printf("1. Parent process ID: %d\n", pid1);

    pid2 = fork();
    if (!pid2)
    {
        pid1 = getpid();
        printf("2. Grand Child process ID: %d\n", pid1);

        pid3 = fork();
        if (!pid3)
        {
            pid1 = getpid();
            printf("3. GrandGrand Child process ID: %d\n", pid1);
        }

        pid4 = fork();
        if (!pid4)
        {
            pid1 = getpid();
            printf("4. GrandGrand Child process ID: %d\n", pid1);
        }

        pid5 = fork();
        if (!pid5)
        {
            pid1 = getpid();
            printf("5. GrandGrand Child process ID: %d\n", pid1);
        }
    }
}