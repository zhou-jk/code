#include <stdio.h>

void CountOff(int n, int m, int out[])
{
    int next[n];
    for (int i = 0; i < n; i++)
        next[i] = (i + 1) % n;
    int cur = n - 1;
    for (int t = 1; t <= n; t++)
    {
        for (int i = 0; i < m - 1; i++)
            cur = next[cur];
        out[next[cur]] = t;
        next[cur] = next[next[cur]];
    }
    return;
}