#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

const int N = 1e6;
signed main()
{
    char str[N], res[100], now = 0;
    gets(str);
    bool lower = false;
    bool upper = false;
    bool digit = false;
    bool special = false;
    for (int i = 0; i < strlen(str); ++i)
    {
        if (isupper(str[i]))
            upper = true;
        if (islower(str[i]))
            lower = true;
        if (isdigit(str[i]))
            digit = true;
        if (str[i] == '_' ||
            str[i] == '$' ||
            str[i] == '#' ||
            str[i] == '@')
            special = true;
    }

    bool missing_found = false;
    if (!lower)
    {
        printf("Lowercase character missing");
        missing_found = true;
    }
    if (!upper)
    {
        if (missing_found)
            printf(", ");
        printf("Uppercase character missing");
        missing_found = true;
    }
    if (!digit)
    {
        if (missing_found)
            printf(", ");
        printf("Digit missing");
        missing_found = true;
    }
    if (!special)
    {
        if (missing_found)
            printf(", ");
        printf("Special character missing");
        missing_found = true;
    }
    if (!missing_found)
    {
        printf("OK");
    }
}