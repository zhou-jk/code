#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    int cnt = 0, val = 0;
    for (int i = 0, j = 0; i < n; i = j)
    {
        while (j < n && a[i] == a[j])
            j++;
        if (j - i > cnt)
            cnt = j - i, val = a[i];
    }
    printf("%d %d", val, cnt);
    return 0;
}