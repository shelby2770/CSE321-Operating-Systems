#include <stdio.h>

signed main()
{
    int i, j, k, m, n;
    n = 6;                            // Number of processes
    m = 4;                            // Number of resources
    int alloc[6][4] = {{0, 1, 0, 3},  // P0 // Allocation Matrix
                       {2, 0, 0, 3},  // P1
                       {3, 0, 2, 0},  // P2
                       {2, 1, 1, 5},  // P3
                       {0, 0, 2, 2},  // P4
                       {1, 2, 3, 1}}; // P5

    int max[6][4] = {{6, 4, 3, 4},  // P0 // MAX Matrix
                     {3, 2, 2, 4},  // P1
                     {9, 1, 2, 6},  // P2
                     {2, 2, 2, 8},  // P3
                     {4, 3, 3, 7},  // P4
                     {6, 2, 6, 5}}; // P5
    int avail[4] = {2, 2, 2, 1};    // Available resources

    int arr[n], ans[n], count = 0;
    for (int i = 0; i < n; ++i)
    {
        arr[i] = 0;
    }

    int need[n][m];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (arr[j] == 0)
            {
                int check = 0;
                for (k = 0; k < m; ++k)
                {
                    if (need[j][k] > avail[k])
                    {
                        check = 1;
                        break;
                    }
                }
                if (check == 0)
                {
                    ans[count] = j;
                    for (int i = 0; i < m; ++i)
                    {
                        avail[i] += alloc[j][i];
                    }
                    arr[j] = 1;
                    count++;
                }
            }
        }
    }

    int check = 1;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == 0)
        {
            check = 0;
            printf("System is not safe");
            break;
        }
    }
    if (check == 1)
    {
        printf("System is safe\n");
        printf("Safe sequence is: ");
        for (i = 0; i < n; ++i)
        {
            printf("%d ", ans[i]);
        }
    }
}