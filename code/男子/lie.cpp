// AC
#include <cstdio>
#include <cstring>

const int N = 22;
int a[1 << N], g[1 << N], n;
bool vis[1 << N];

void dfs(int num)
{
	vis[num] = true;
	if (~g[num] && !vis[g[num]]) dfs(g[num]);
	for (int i = 0; i < n; ++i)
		if (num & (1 << i))
		{
			int tmp = num ^ (1 << i);
			if (!vis[tmp]) dfs(tmp);
		}
}

int main()
{
	freopen("lie.in", "r", stdin);
	freopen("lie.out", "w", stdout);
	int m, ans = 0;
	scanf("%d%d", &n, &m);
	int s = (1 << n) - 1;
	memset(g, -1, sizeof g);
	for (int i = 0; i < m; ++i) scanf("%d", a + i), g[a[i]] = a[i] ^ s;
	for (int i = 0; i < m; ++i)
		if (!vis[a[i]]) vis[a[i]] = true, ++ans, dfs(a[i] ^ s);
	printf("%d", ans);
	return 0;
}