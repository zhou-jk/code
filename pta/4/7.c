#include <stdio.h>
const int N = 10;

int main()
{
    int n;
    scanf("%d", &n);
    int fac[N + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += fac[i];
    printf("%d", ans);
    return 0;
}