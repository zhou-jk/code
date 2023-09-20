#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int fac[10001];
    int cnt = 0;
    for (int x = m; x <= n; x++)
    {
        int tot = 0, sum = 0;
        for (int i = 1; i < x; i++)
            if (x % i == 0)
                sum += i, fac[++tot] = i;
        if (sum == x)
        {
            cnt++;
            printf("%d = ", x);
            for (int i = 1; i < tot; i++)
                printf("%d + ", fac[i]);
            printf("%d\n", fac[tot]);
        }
    }
    if (cnt == 0)
        printf("None");
    return 0;
}