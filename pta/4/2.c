#include <stdio.h>

int main()
{
    int n, u, d;
    scanf("%d%d%d", &n, &u, &d);
    int now = 0, cnt = 0;
    while (now < n)
    {
        now += u;
        cnt++;
        if (now >= n)
            break;
        now -= d;
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}