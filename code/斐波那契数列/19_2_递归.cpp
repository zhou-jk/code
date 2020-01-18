// AC
#include <cstdio>

int dfs(int n)
{
	if (n < 3) return n - 1;
	return dfs(n - 1) + dfs(n - 2);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", dfs(n));
	return 0;
}