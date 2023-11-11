#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[21][21];
    int cur = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        for (int j = i; j < n - i + 1; j++)
            a[j][n - i + 1] = ++cur;
        for (int j = n - i + 1; j > i; j--)
            a[n - i + 1][j] = ++cur;
        for (int j = n - i + 1; j > i; j--)
            a[j][i] = ++cur;
        for (int j = i; j < n - i + 1; j++)
            a[i][j] = ++cur;
    }
    if (n % 2 == 1)
        a[(n + 1) / 2][(n + 1) / 2] = ++cur;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
    return 0;
}