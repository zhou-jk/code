#include <stdio.h>

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int a, b;
    scanf("%d/%d", &a, &b);
    int c = gcd(a, b);
    printf("%d/%d", a / c, b / c);
    return 0;
}