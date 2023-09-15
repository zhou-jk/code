#include <stdio.h>

struct Student
{
    char id[6];
    char name[11];
    int a, b, c, sum;
};

int main()
{
    int n;
    scanf("%d", &n);
    struct Student a[10];
    for (int i = 0; i < n; i++)
        scanf("%s%s%d%d%d", a[i].id, a[i].name, &a[i].a, &a[i].b, &a[i].c);
    for (int i = 0; i < n; i++)
        a[i].sum = a[i].a + a[i].b + a[i].c;
    int p = 0;
    for (int i = 1; i < n; i++)
        if (a[i].sum > a[p].sum)
            p = i;
    printf("%s %s %d", a[p].name, a[p].id, a[p].sum);
    return 0;
}