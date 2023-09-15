#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int c[11] = {0};
    for (int i = 0; i < n; i++)
        if (a[i] <= 100)
            c[a[i] / 10]++;
    for (int i = 0; i <= 10; i++)
        printf("%d: %d\n", i, c[i]);
    return 0;
}