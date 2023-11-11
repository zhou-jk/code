#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[10];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    for (int i = 0; i < n - 1; i++)
        printf("%d ", a[i]);
    printf("%d", a[n - 1]);
    return 0;
}