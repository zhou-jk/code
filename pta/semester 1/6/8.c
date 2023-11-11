#include <stdio.h>

int main()
{
    int a[7];
    for (int i = 1; i <= 6; i++)
        scanf("%d", &a[i]);
    int n;
    scanf("%d", &n);
    int vis[7][7] = {};
    for (int i = 1; i <= 6; i++)
        vis[i][a[i]] = 1;
    for (int t = 1; t <= n; t++)
    {
        for (int i = 1; i <= 6; i++)
        {
            int v = 0;
            for (int j = 6; j >= 1; j--)
                if (!vis[i][j])
                {
                    v = j;
                    break;
                }
            a[i] = v;
            vis[i][v] = 1;
        }
    }
    for (int i = 1; i <= 6; i++)
    {
        printf("%d", a[i]);
        if (i < 6)
            printf(" ");
    }
    return 0;
}