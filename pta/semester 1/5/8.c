#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int n;
    scanf("%d", &n);
    int cura = 0, curb = 0;
    for (int i = 1; i <= n; i++)
    {
        int ya, yb, ca, cb;
        scanf("%d%d%d%d", &ya, &ca, &yb, &cb);
        if (ca == ya + yb && cb != ya + yb)
            cura++;
        if (ca != ya + yb && cb == ya + yb)
            curb++;
        if (cura > a)
        {
            printf("A\n");
            printf("%d", curb);
            return 0;
        }
        if (curb > b)
        {
            printf("B\n");
            printf("%d", cura);
            return 0;
        }
    }
    return 0;
}