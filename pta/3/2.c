#include <stdio.h>

int main()
{
    double w, h;
    scanf("%lf%lf", &w, &h);
    double ans = w / (h * h);
    printf("%.1lf\n", ans);
    if (ans > 25)
        printf("PANG");
    else
        printf("Hai Xing");
    return 0;
}