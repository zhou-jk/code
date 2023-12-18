#include <stdio.h>

int factorsum(int number)
{
    int sum = 0;
    for (int i = 1; i < number; i++)
        if (number % i == 0)
            sum += i;
    return sum;
}
void PrintPN(int m, int n)
{
    int cnt = 0;
    for (int i = m; i <= n; i++)
        if (factorsum(i) == i)
        {
            cnt++;
            printf("%d = 1", i);
            for (int d = 2; d < i; d++)
                if (i % d == 0)
                    printf(" + %d", d);
            printf("\n");
        }
    if (cnt == 0)
        printf("No perfect number");
    return;
}