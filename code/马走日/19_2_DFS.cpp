// AC
#include <cstdio>

const int N = 10, N_DIR = 8, dx[N_DIR] = {-1, -2, -2, -1, 1, 2, 2, 1},
		  dy[N_DIR] = {-2, -1, 1, 2, -2, -1, 1, 2};
int n, m, ans;
bool vis[N][N];

void dfs(int x, int y, int cnt)
{
	if (cnt + 1 == n * m) ++ans;
	vis[x][y] = true;
	for (int i = 0; i < N_DIR; ++i)
	{
		int tx = x + dx[i], ty = y + dy[i];
		if (tx >= 0 && tx < n && ty >= 0 && ty < m && !vis[tx][ty])
			dfs(tx, ty, cnt + 1);
	}
	vis[x][y] = false;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int x, y;
		scanf("%d%d%d%d", &n, &m, &x, &y);
		ans = 0;
		dfs(x, y, 0);
		printf("%d\n", ans);
	}
	return 0;
}