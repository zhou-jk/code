// AC
#include <cmath>
#include <cstdio>

int dfs(int n, int s)
{
	if (n < s) return 0;
	int m = sqrt(n), ret = 1;
	for (int i = s; i <= m; ++i)
		if (!(n % i)) ret += dfs(n / i, i);
	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", dfs(n, 2));
	}
	return 0;
}