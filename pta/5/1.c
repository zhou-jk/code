#include <stdio.h>

int main()
{
    int a[24];
    for (int i = 0; i < 24; i++)
        scanf("%d", &a[i]);
    int hour;
    while (1)
    {
        scanf("%d", &hour);
        if (hour < 0 || hour > 23)
            break;
        if (a[hour] > 50)
            printf("%d Yes\n", a[hour]);
        else
            printf("%d No\n", a[hour]);
    }
    return 0;
}