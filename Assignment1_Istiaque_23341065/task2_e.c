#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const int N=1e6;
signed main()
{
    char str[N];
    scanf("%s", str);
    bool ok = true;
    for (int i = 0; i < strlen(str) / 2; ++i)
    {
        if (str[i] != str[strlen(str) - i - 1])
        {
            ok = false;
            break;
        }
    }
    printf(ok ? "Palindrome" : "Not Palindrome");
}
