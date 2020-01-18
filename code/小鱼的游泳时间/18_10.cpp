#include <cstdio>

int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int tmp = d + 60 - b;
    printf("%d %d", c - a - 1 + tmp / 60, tmp % 60);
    return 0;
}