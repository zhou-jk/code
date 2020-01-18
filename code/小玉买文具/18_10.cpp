#include <cstdio>

const int unit_price = 19;

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", (a * 10 + b) / unit_price);
    return 0;
}
