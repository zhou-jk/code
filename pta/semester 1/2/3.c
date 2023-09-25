#include <stdio.h>

int main()
{
    int h;
    scanf("%d", &h);
    double w = (h - 100) * 0.9 * 2;
    printf("%.1lf", w);
    return 0;
}