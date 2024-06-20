#include <stdio.h>
#include <string.h>

const int N = 1e6;
signed main()
{
    char str[N];
    gets(str);
    strstr(str, "@sheba.xyz") ? printf("Email address is okay") : printf("Email address is outdated");
}
