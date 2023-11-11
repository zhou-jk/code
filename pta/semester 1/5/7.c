#include <stdio.h>
#include <math.h>

int n;
int pw[10];
void dfs(int step, int sum, int sumpw)
{
    if (step > n)
    {
        if (sum == sumpw)
            printf("%d\n", sum);
        return;
    }
    if (step != 1)
        dfs(step + 1, sum * 10, sumpw);
    for (int i = 1; i <= 9; i++)
        dfs(step + 1, sum * 10 + i, sumpw + pw[i]);
    return;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 9; i++)
        pw[i] = pow(i, n);
    dfs(1, 0, 0);
    return 0;
}