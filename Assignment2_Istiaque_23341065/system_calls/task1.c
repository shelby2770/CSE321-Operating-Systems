#include <stdio.h>
#include <string.h>

const int N = 1e6;
signed main(int argc, char *argv[])
{
    if (argc == 2)
    {
        FILE *fp;
        char fname[N], str[N];
        strcpy(fname, argv[1]);
        fp = fopen(fname, "ab+");
        while (strcmp(str, "-1"))
        {
            fprintf(fp, "%s\n", str);
            scanf("%s", str);
        }
        fclose(fp);
    }
}
