#include <stdio.h>

int main()
{
    int t;
    char ch;
    scanf("%d %c", &t, &ch);
    for (int n = 1;; n++)
        if (2 * n * n - 1 > t)
        {
            n--;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= i - 1; j++)
                    printf(" ");
                for (int j = 1; j <= 2 * (n - i + 1) - 1; j++)
                    printf("%c", ch);
                printf("\n");
            }
            for (int i = 2; i <= n; i++)
            {
                for (int j = 1; j <= n - i; j++)
                    printf(" ");
                for (int j = 1; j <= 2 * i - 1; j++)
                    printf("%c", ch);
                printf("\n");
            }
            printf("%d", t - (2 * n * n - 1));
            return 0;
        }
    return 0;
}