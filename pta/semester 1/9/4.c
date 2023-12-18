#include <stdio.h>

int fib(int n)
{
    if (n <= 2)
        return 1;
    int a = 1, b = 1, c = a + b;
    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        a = b, b = c;
    }
    return c;
}
void PrintFN(int m, int n)
{
    int cnt = 0;
    if (m <= 1 && 1 <= n)
    {
        if (cnt >= 1)
            printf(" ");
        cnt++;
        printf("1 1");
    }
    int a = 1, b = 1, c = a + b;
    while (c <= n)
    {
        c = a + b;
        if (m <= c && c <= n)
        {
            if (cnt >= 1)
                printf(" ");
            cnt++;
            printf("%d", c);
        }
        a = b, b = c;
    }
    if (cnt == 0)
        printf("No Fibonacci number");
    return;
}