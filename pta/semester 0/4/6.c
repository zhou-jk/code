#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int x = 1; x * x <= n; x++)
    {
        int y = sqrt(n - x * x);
        if (x <= y && x * x + y * y == n)
        {
            cnt++;
            printf("%d %d\n", x, y);
        }
    }
    if (cnt == 0)
        printf("No Solution");
    return 0;
}