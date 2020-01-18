// AC
#include <cstdio>

const int N = 20, N_DIR = 4, dx[N_DIR] = {1, -1, 0, 0},
		  dy[N_DIR] = {0, 0, 1, -1};
char a[N][N + 1];
int ans, n, m;

void dfs(int x, int y)
{
	++ans;
	a[x][y] = '#';
	for (int i = 0; i < N_DIR; ++i)
	{
		int tx = x + dx[i], ty = y + dy[i];
		if (tx >= 0 && tx < n && ty >= 0 && ty < m && a[tx][ty] == '.')
			dfs(tx, ty);
	}
}

int main()
{
	while (scanf("%d%d", &m, &n) != EOF && n && m)
	{
		for (int i = 0; i < n; ++i) scanf("%s", a[i]);
		int x, y;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (a[i][j] == '@')
				{
					x = i;
					y = j;
					break;
				}
		ans = 0;
		dfs(x, y);
		printf("%d\n", ans);
	}
	return 0;
}