#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[10];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int p = 0;
    for (int i = 1; i < n; i++)
        if (a[i] > a[p])
            p = i;
    printf("%d %d", a[p], p);
    return 0;
}