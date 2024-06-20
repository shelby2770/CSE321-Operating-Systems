#include <stdio.h>

signed main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    for (int i = a; i <= b; ++i)
    {
        int sum = 0;
        for (int j = 1; j < i; ++j)
        {
            if (i % j == 0)
                sum += j;
        }
        if (sum == i)
            printf("%d\n", i);
    }
}