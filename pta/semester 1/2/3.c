#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            printf("%c ", (char)(c + 'A'));
            c++;
        }
        printf("\n");
    }
    return 0;
}