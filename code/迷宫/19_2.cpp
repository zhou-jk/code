// AC
#include <cstdio>
#include <cstring>

const int N = 100, N_DIR = 4, dx[N_DIR] = {1, -1, 0, 0},
		  dy[N_DIR] = {0, 0, 1, -1};
char map[N][N + 1];
bool vis[N][N];
int n;

void dfs(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= n || map[x][y] == '#' || vis[x][y])
		return;
	vis[x][y] = true;
	for (int i = 0; i < N_DIR; ++i) dfs(x + dx[i], y + dy[i]);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int xA, yA, xB, yB;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%s", map[i]);
		scanf("%d%d%d%d", &xA, &yA, &xB, &yB);
		memset(vis, false, sizeof vis);
		dfs(xA, yA);
		puts(vis[xB][yB] ? "YES" : "NO");
	}
	return 0;
}