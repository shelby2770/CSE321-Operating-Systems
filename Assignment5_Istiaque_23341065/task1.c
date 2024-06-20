#include <stdio.h>

const int N = 100;

signed main()
{
    int alloc[N][N], max[N][N], avail[N][N], n, m;

    printf("Number of processes: ");
    scanf("%d", &n);
    printf("Number of resources: ");
    scanf("%d", &m);
    printf("Allocation Matrix:\n");

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("MAX Matrix:\n");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Available resources:\n");
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &avail[0][i]);
    }

    int finish[N], dead[N], safe[N], need[N][N], check = 1, count = 0, k, temp;
    for (int i = 0; i < n; ++i)
    {
        finish[i] = 0;
        dead[i] = 0;
        safe[i] = 0;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    while (check)
    {
        check = 0;
        for (int i = 0; i < n; ++i)
        {
            int c = 0;
            for (int j = 0; j < m; ++j)
            {
                if (finish[i] == 0 && need[i][j] <= avail[0][j])
                {
                    c++;
                    if (c == m)
                    {
                        for (k = 0; k < m; k++)
                        {
                            avail[0][k] = avail[0][k] + alloc[i][k];
                            finish[i] = 1;
                            check = 1;
                        }
                        if (finish[i] == 1)
                        {
                            i = n;
                        }
                    }
                }
            }
        }
    }

    int j = 0;
    check = 0;
    for (int i = 0; i < n; ++i)
    {
        if (finish[i] == 0)
        {
            dead[j] = i;
            j++;
            check = 1;
        }
    }
    printf(check ? "Deadlock Ahead" : "Safe Ahead");
}