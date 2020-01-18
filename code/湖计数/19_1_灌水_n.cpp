// AC
#include <cstdio>

const int dx[] = {1, 1, 1, -1, -1, -1, 0, 0},
		  dy[] = {1, 0, -1, 1, 0, -1, 1, -1}, N = 100;
char map[N][N + 1];
int n, m;

void dfs(int x, int y)
{
	map[x][y] = '.';
	for (int i = 0; i < 8; ++i)
	{
		int tx = x + dx[i], ty = y + dy[i];
		if (~tx && tx < n && ~ty && ty < m && map[tx][ty] == 'W') dfs(tx, ty);
	}
}

int main()
{
	int ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%s", map[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (map[i][j] == 'W') ++ans, dfs(i, j);
	printf("%d", ans);
	return 0;
}