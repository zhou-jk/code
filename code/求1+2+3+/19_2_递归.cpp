//AC
#include <cstdio>

int dfs(int n)
{
    if (!n) return 0;
    return dfs(n-1)+n;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",dfs(n));
    return 0;
}