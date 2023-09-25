#include <stdio.h>

int calc(int n)
{
    int sum = 0;
    while (n > 0)
        sum += n % 10, n /= 10;
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    int cur = 1;
    for (int i = 1; i < 1000; i++)
        if (calc(i) == n)
        {
            cur++;
            printf("%8d", i);
            if (cur == 7)
            {
                printf("\n");
                cur = 1;
            }
        }
    if (cur != 1)
        printf("\n");
    return 0;
}