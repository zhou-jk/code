#include <stdio.h>

int main()
{
    int h;
    scanf("%d", &h);
    printf("%.1lf", (h - 100) * 0.9 * 2);
    return 0;
}