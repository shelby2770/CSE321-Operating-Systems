#include <stdio.h>
#include <unistd.h>

signed main()
{
    pid_t p1 = fork();
    if (!p1)
    {
        pid_t p2 = fork();
        if (!p2)
        {
            printf("I am grandchild\n");
        }
        else
        {
            wait(0);
            printf("I am child\n");
        }
    }
    else
    {
        wait(0);
        printf("I am parent\n");
    }
}