#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[1001];
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int c[10] = {};
    for (int i = 1; i <= n; i++)
    {
        int u = a[i];
        if (u == 0)
        {
            c[0]++;
            continue;
        }
        while (u)
            c[u % 10]++, u /= 10;
    }
    int m = 0;
    for (int i = 0; i <= 9; i++)
        if (c[i] > m)
            m = c[i];
    printf("%d:", m);
    for (int i = 0; i <= 9; i++)
        if (c[i] == m)
            printf(" %d", i);
    return 0;
}