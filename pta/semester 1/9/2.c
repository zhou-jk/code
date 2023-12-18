#include <stdio.h>

int prime(int p)
{
    if (p == 1)
        return 0;
    for (int i = 2; i * i <= p; i++)
        if (p % i == 0)
            return 0;
    return 1;
}

void Goldbach(int n)
{
    for (int p = 1; p <= n; p++)
    {
        int q = n - p;
        if (p % 2 == 1 && q % 2 == 1 && prime(p) && prime(q))
        {
            printf("%d=%d+%d", n, p, q);
            return;
        }
    }
    return;
}