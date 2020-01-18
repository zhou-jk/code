#include <cstdio>

const int N = 21;
int ans[N], n, m;

void dfs(int s, int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; ++i) printf("%3d", ans[i]);
		putchar('\n');
		return;
	}
	for (int i = s; i <= n; ++i)
	{
		ans[k] = i;
		dfs(i + 1, k + 1);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	dfs(1, 0);
	return 0;
}