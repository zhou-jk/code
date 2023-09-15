#include <stdio.h>

struct Student
{
    int sex;
    char name[9];
};

int main()
{
    int n;
    scanf("%d", &n);
    struct Student a[50];
    for (int i = 0; i < n; i++)
        scanf("%d%s", &a[i].sex, a[i].name);
    int book[50];
    for (int i = 0; i < n; i++)
        book[i] = 0;
    int lst[2] = {n - 1, n - 1};
    for (int i = 0; i < n; i++)
        if (!book[i])
        {
            int cur = a[i].sex ^ 1;
            while (a[lst[cur]].sex != cur || book[lst[cur]])
                lst[cur]--;
            book[i] = book[lst[cur]] = 1;
            printf("%s %s\n", a[i].name, a[lst[cur]].name);
        }
    return 0;
}