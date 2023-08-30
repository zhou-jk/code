#include <stdio.h>

int main()
{
    int n, m, k;
    char x[10];
    scanf("%d %s %d %d", &n, x, &m, &k);
    if (k == n)
        printf("mei you mai %s de", x);
    else if (k == m)
        printf("kan dao le mai %s de", x);
    else
        printf("wang le zhao mai %s de", x);
    return 0;
}