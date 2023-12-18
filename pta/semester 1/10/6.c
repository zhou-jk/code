#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    long long number[1000];
    int index[1000], pos[1000];
    for (int i = 0; i < n; i++)
        scanf("%lld%d%d", &number[i], &index[i], &pos[i]);
    int m;
    scanf("%d", &m);
    for (int t = 1; t <= m; t++)
    {
        int id;
        scanf("%d", &id);
        for (int i = 0; i < n; i++)
            if (index[i] == id)
            {
                printf("%lld %d\n", number[i], pos[i]);
                break;
            }
    }
    return 0;
}