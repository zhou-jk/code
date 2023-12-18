#include <stdio.h>

int main()
{
    int forbid, accompany, a, b;
    scanf("%d%d%d%d", &forbid, &accompany, &a, &b);
    if (a >= forbid && b >= forbid)
    {
        printf("%d-Y %d-Y\n", a, b);
        printf("huan ying ru guan");
    }
    else if (a >= accompany)
    {
        printf("%d-Y %d-Y\n", a, b);
        printf("qing 1 zhao gu hao 2");
    }
    else if (b >= accompany)
    {
        printf("%d-Y %d-Y\n", a, b);
        printf("qing 2 zhao gu hao 1");
    }
    else if (a >= forbid)
    {
        printf("%d-Y %d-N\n", a, b);
        printf("1: huan ying ru guan");
    }
    else if (b >= forbid)
    {
        printf("%d-N %d-Y\n", a, b);
        printf("2: huan ying ru guan");
    }
    else
    {
        printf("%d-N %d-N\n", a, b);
        printf("zhang da zai lai ba");
    }
    return 0;
}