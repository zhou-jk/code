// AC
#include <cstdio>

int n, m, ans;

void dfs(int k, int sum, int last)
{
	if (k == m)
	{
		ans += sum == n;
		return;
	}
	for (int i = last; sum + (m - k) * i <= n; ++i) dfs(k + 1, sum + i, i);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		ans = 0;
		dfs(0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}