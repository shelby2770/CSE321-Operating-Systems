#include <stdio.h>

signed main()
{
    int num1, num2, ans;
    scanf("%d", &num1);
    scanf("%d", &num2);
    if (num1 > num2)
        ans = num1 - num2;
    else if (num1 < num2)
        ans = num1 + num2;
    else
        ans = num1 * num2;
    printf("%d", ans);
}