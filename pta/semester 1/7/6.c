#include <stdio.h>

int calc(int n)
{
    int c[10] = {};
    for (int i = 1; i <= 4; i++)
        c[n % 10]++, n /= 10;
    int cnt = 0;
    for (int i = 0; i <= 9; i++)
        if (c[i])
            cnt++;
    return cnt;
}
int main()
{
    int y, n;
    scanf("%d%d", &y, &n);
    for (int x = 0;; x++)
        if (calc(y + x) == n)
        {
            printf("%d %04d", x, y + x);
            return 0;
        }
    return 0;
}