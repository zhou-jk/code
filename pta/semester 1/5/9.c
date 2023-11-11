#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[10];
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += a[i] * 11 * (n - 1);
    printf("%d", ans);
    return 0;
}