#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    int res = x / 100 + x / 10 % 10 * 10 + x % 10 * 100;
    printf("%d", res);
    return 0;
}