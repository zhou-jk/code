#include <stdio.h>
#define N 10005
int a, b;
int independence[N], ishappy[N];
int vis[N];
int num[N];
int isprime(int x)
{
    if (x == 1)
        return 0;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
int iterate(int x)
{
    int res = 0;
    while (x)
        res += (x % 10) * (x % 10), x /= 10;
    return res;
}
int check(int u)
{
    if (u == 1)
        return 1;
    if (vis[u])
        return 0;
    vis[u] = 1;
    num[u] = 1;
    int v = iterate(u);
    vis[u] = check(v);
    if (vis[u])
        num[u] += num[v], independence[v] = 0;
    return vis[u];
}
int main()
{
    scanf("%d%d", &a, &b);
    for (int i = 1; i <= b; i++)
        independence[i] = 1;
    for (int x = a; x <= b; x++)
    {
        for (int i = 1; i <= 9 * 9 * 4; i++)
            vis[i] = 0;
        ishappy[x] = check(x);
    }
    int cnt = 0;
    for (int x = a; x <= b; x++)
        if (ishappy[x] && independence[x])
        {
            cnt++;
            if (isprime(x))
                num[x] *= 2;
            printf("%d %d\n", x, num[x]);
        }
    if (cnt == 0)
        printf("SAD");
    return 0;
}