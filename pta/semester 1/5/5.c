#include <stdio.h>

int main()
{
    int x, n;
    scanf("%d%d", &x, &n);
    for (int i = 1; i <= n; i++)
    {
        int val;
        scanf("%d", &val);
        if (val < 0)
        {
            printf("Game Over");
            return 0;
        }
        if (val > x)
            printf("Too big\n");
        else if (val < x)
            printf("Too small\n");
        else
        {
            if (i <= 1)
                printf("Bingo!");
            else if (i <= 3)
                printf("Lucky You!");
            else
                printf("Good Guess!");
            return 0;
        }
    }
    printf("Game Over");
    return 0;
}