// AC
#include <cstdio>

const int N = 20;
char a[N][N + 1];
int n, m, ans;
bool vis[26];

void dfs(int x, int y, int cnt)
{
	if (x < 0 || x >= n || y < 0 || y >= m) return;
	int tmp = a[x][y] - 'A';
	if (cnt > ans) ans = cnt;
	if (vis[tmp]) return;
	vis[tmp] = true;
	dfs(x - 1, y, cnt + 1);
	dfs(x + 1, y, cnt + 1);
	dfs(x, y - 1, cnt + 1);
	dfs(x, y + 1, cnt + 1);
	vis[tmp] = false;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%s", a[i]);
	dfs(0, 0, 0);
	printf("%d", ans);
	return 0;
}