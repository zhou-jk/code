#include <stdio.h>
#include <stdlib.h>

struct People
{
    char name[11], phone[18];
    int day;
};

int cmp(const void *a, const void *b)
{
    return (((struct People *)a)->day - ((struct People *)b)->day);
}

int main()
{
    int n;
    scanf("%d", &n);
    struct People a[10];
    for (int i = 0; i < n; i++)
        scanf("%s%d%s", a[i].name, &a[i].day, a[i].phone);
    qsort(a, n, sizeof(struct People), cmp);
    for (int i = 0; i < n; i++)
        printf("%s %d %s\n", a[i].name, a[i].day, a[i].phone);
    return 0;
}