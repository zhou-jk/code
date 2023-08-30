#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int C[11][11];
    for (int i = 0; i <= n; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            C[i][j] = C[i - 1][j - 1];
            if (j <= i - 1)
                C[i][j] += C[i - 1][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            printf(" ");
        for (int j = 0; j <= i; j++)
            printf("%4d", C[i][j]);
        printf("\n");
    }
    return 0;
}