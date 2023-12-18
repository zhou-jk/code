#include <stdio.h>

int fn(int a, int n)
{
    int number = 0;
    for (int i = 1; i <= n; i++)
        number = number * 10 + a;
    return number;
}
int SumA(int a, int n)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += fn(a, i);
    return ans;
}