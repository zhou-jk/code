// AC
#include <cstdio>

const int N = 8;
char a[N][N + 1];
int n, m, ans;
bool vis[N];

void dfs(int k, int cnt)
{
	if (cnt == m)
	{
		++ans;
		return;
	}
	if (k == n) return;
	dfs(k + 1, cnt);
	for (int i = 0; i < n; ++i)
		if (a[k][i] == '#' && !vis[i])
		{
			vis[i] = true;
			dfs(k + 1, cnt + 1);
			vis[i] = false;
		}
}

int main()
{
	while (scanf("%d%d", &n, &m) != EOF && ~n && ~m)
	{
		for (int i = 0; i < n; ++i) scanf("%s", a[i]);
		ans = 0;
		dfs(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}