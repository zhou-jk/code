#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = 1; i <= a + b; i++)
        printf("Wang!");
    return 0;
}