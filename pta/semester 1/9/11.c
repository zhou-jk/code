#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d=", n);
    if (n == 1)
        printf("1");
    int cnt = 0;
    for (int i = 2; i <= n; i++)
        if (n % i == 0)
        {
            int k = 0;
            while (n % i == 0)
                n /= i, k++;
            if (cnt >= 1)
                printf("*");
            cnt++;
            printf("%d", i);
            if (k > 1)
                printf("^%d", k);
        }
    return 0;
}