#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int cnt[1001] = {};
    for (int t = 1; t <= n; t++)
    {
        int k;
        scanf("%d", &k);
        for (int i = 1; i <= k; i++)
        {
            int f;
            scanf("%d", &f);
            cnt[f]++;
        }
    }
    int mx = 0;
    for (int i = 1; i <= 1000; i++)
        if (cnt[i] > mx)
            mx = cnt[i];
    for (int i = 1000; i >= 1; i--)
        if (cnt[i] == mx)
        {
            printf("%d %d", i, cnt[i]);
            return 0;
        }
    return 0;
}