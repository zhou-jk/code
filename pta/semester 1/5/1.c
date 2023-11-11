#include <stdio.h>

void hollowPyramid(int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            printf(" ");
        printf("%d", i);
        if (i > 1)
        {
            for (int j = 1; j <= 2 * (i - 1) - 1; j++)
                printf(" ");
            printf("%d", i);
        }
        printf("\n");
    }
    for (int j = 1; j <= n * 2 - 1; j++)
        printf("%d", n);
    return;
}