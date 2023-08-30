#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n < 100 || n > 999)
    {
        printf("Invalid Value.");
        return 0;
    }
    int a = n / 100, b = n / 10 % 10, c = n % 10;
    if (a * a * a + b * b * b + c * c * c == n)
        printf("Yes");
    else
        printf("No");
    return 0;
}