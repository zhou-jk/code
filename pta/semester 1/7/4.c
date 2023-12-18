#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int ans = a * b;
    int stk[8], top = 0;
    while (ans)
        stk[++top] = ans % 10, ans /= 10;
    int i = 1;
    while (stk[i] == 0 && i < top)
        i++;
    for (; i <= top; i++)
        printf("%d", stk[i]);
    return 0;
}