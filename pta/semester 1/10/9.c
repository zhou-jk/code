#include <stdio.h>
#include <stdlib.h>

struct People
{
    int id;
    int h, m, s;
    int time;
};

int cmp(const void *a, const void *b)
{
    if (((struct People *)b)->time == ((struct People *)a)->time)
        return (((struct People *)a)->id - ((struct People *)b)->id);
    else
        return (((struct People *)b)->time - ((struct People *)a)->time);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    struct People a[1000];
    for (int i = 0; i < n; i++)
        a[i].id = i, a[i].h = a[i].m = a[i].s = 0, a[i].time = 0;
    for (int t = 1; t <= m; t++)
    {
        int i, sh, sm, ss, th, tm, ts;
        scanf("%3d %2d:%2d:%2d %2d:%2d:%2d", &i, &sh, &sm, &ss, &th, &tm, &ts);
        int h = th - sh, m = tm - sm, s = ts - ss;
        if (s < 0)
            m--, s += 60;
        if (m < 0)
            h--, m += 60;
        a[i].h += h, a[i].m += m, a[i].s += s;
        if (a[i].s >= 60)
            a[i].m++, a[i].s -= 60;
        if (a[i].m >= 60)
            a[i].h++, a[i].m -= 60;
        a[i].time += h * 60 * 60 + m * 60 + s;
    }
    qsort(a, n, sizeof(struct People), cmp);
    for (int i = 0; i < n; i++)
        printf("%03d %02d:%02d:%02d\n", a[i].id, a[i].h, a[i].m, a[i].s);
    return 0;
}