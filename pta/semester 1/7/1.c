#include <stdio.h>

int main()
{
    int n;
    scanf("%d\n", &n);
    for (int t = 1; t <= n; t++)
    {
        char index[5], answer[5];
        scanf("%c-%c %c-%c %c-%c %c-%c\n", &index[1], &answer[1], &index[2], &answer[2], &index[3], &answer[3], &index[4], &answer[4]);
        for (int i = 1; i <= 4; i++)
            if (answer[i] == 'T')
            {
                printf("%d", (int)(index[i] - 'A' + 1));
            }
    }
    return 0;
}