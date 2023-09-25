#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 0)
    {
        printf("0 0");
        return 0;
    }
    int len = 0, sum = 0;
    while (n > 0)
        len++, sum += n % 10, n /= 10;
    printf("%d %d", len, sum);
    return 0;
}