#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[11];
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[n - i + 1]);
    for (int i = 1; i <= n; i++)
    {
        printf("%d", a[i]);
        if (i < n)
            printf(" ");
    }
    return 0;
}