#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        double p;
        scanf("%lf", &p);
        if (p < m)
            printf("On Sale! %.1lf\n", p);
    }
    return 0;
}