#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int ans = a + b;
    printf("%d\n%d\n%d\n%d", ans - 16, ans - 3, ans - 1, ans);
    return 0;
}