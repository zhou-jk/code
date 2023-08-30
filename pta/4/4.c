#include <stdio.h>

int main()
{
    int x;
    int cnt = 0;
    while (scanf("%d", &x) != EOF)
    {
        cnt++;
        if (x == 250)
        {
            printf("%d", cnt);
            return 0;
        }
    }
    return 0;
}