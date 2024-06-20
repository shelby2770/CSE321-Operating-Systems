#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int N = 1e6;
signed main()
{
    char str[N], res[N];
    gets(str);
    int now = 0;
    bool space = true;
    for (int i = 0; i < strlen(str); ++i)
    {
        if (str[i] == ' ' && space)
            continue;
        res[now] = str[i];
        if (str[i] == ' ')
            space = true;
        else
            space = false;
        now++;
    }
    res[now] = '\0';
    printf("%s", res);
}