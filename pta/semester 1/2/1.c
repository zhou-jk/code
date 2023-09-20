#include <stdio.h>

int check(int year)
{
    if (year % 400 == 0)
        return 1;
    else if (year % 100 == 0)
        return 0;
    else if (year % 4 == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 2000 || n > 2100)
    {
        printf("Invalid year!");
        return 0;
    }
    int cnt = 0;
    for (int i = 2001; i <= n; i++)
        if (check(i))
        {
            printf("%d\n", i);
            cnt++;
        }
    if (cnt == 0)
        printf("None");
    return 0;
}