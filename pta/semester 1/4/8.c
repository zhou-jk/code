#include <stdio.h>

const int N = 10000;
int isprime[N + 1];
int prime[N + 1], tot;
void init(int n)
{
    for (int i = 1; i <= n; i++)
        isprime[i] = 1;
    isprime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isprime[i])
            prime[++tot] = i;
        for (int j = 1; j <= tot && i * prime[j] <= n; j++)
        {
            isprime[i * prime[j]] = 0;
            if (i % prime[j] == 0)
                break;
        }
    }
    return;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    init(n);
    int sum = 0;
    for (int i = tot; i >= 1 && tot - i + 1 <= k; i--)
    {
        printf("%d", prime[i]);
        sum += prime[i];
        if (i == 1 || tot - i + 1 == k)
            printf("=");
        else
            printf("+");
    }
    printf("%d", sum);
    return 0;
}