#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int w, v, p;
} Goods;

int dfs(const Goods a[], const int n, const int retw, const int retv, const int sump, const int retc, const int cur)
{
    if (cur >= n)
        return sump;
    int res = dfs(a, n, retw, retv, sump, retc, cur + 1);
    if (retw >= a[cur].w && retv >= a[cur].v && retc >= 1)
    {
        int now = dfs(a, n, retw - a[cur].w, retv - a[cur].v, sump + a[cur].p, retc - 1, cur + 1);
        if (now > res)
            res = now;
    }
    return res;
}

int knapsack(const Goods a[], const int n, const int w, const int v, const int c)
{
    return dfs(a, n, w, v, 0, c, 0);
}

int main()
{
    int n, w, v, c;
    scanf("%d%d%d%d", &n, &w, &v, &c);
    Goods *a = (Goods *)malloc(sizeof(Goods) * n);
    for (int i = 0; i < n; i++)
        scanf("%d%d%d", &a[i].w, &a[i].v, &a[i].p);
    printf("%d", knapsack(a, n, w, v, c));
    free(a);
    return 0;
}