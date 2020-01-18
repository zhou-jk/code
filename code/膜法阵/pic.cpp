#include <cstdio>
#include <cstring>

const int N = 800 + 2, K = 6, N_DIR = 4;
const int dx[N_DIR] = {1, -1, 0, 0}, dy[N_DIR] = {0, 0, 1, -1};
int f[N][N], n, m, cnt;
bool ans[N * N + 1], vis[N][N];
char a[N][N], t[K] = {'E', 'A', 'F', 'B', 'D', 'C'};

void dfs1(int x, int y)
{
	f[x][y] = cnt;
	for (int i = 0; i < N_DIR; ++i)
	{
		int tx = x + dx[i], ty = y + dy[i];
		if (~tx && tx < n && ~ty && ty < m && a[tx][ty] == a[x][y]
			&& !f[tx][ty])
			dfs1(tx, ty);
	}
}

void dfs2(int x, int y)
{
	vis[x][y] = true;
	for (int i = 0; i < N_DIR; ++i)
	{
		int tx = x + dx[i], ty = y + dy[i];
		if (~tx && tx < n && ~ty && ty < m)
		{
			if (f[tx][ty] == f[x][y])
			{
				if (!vis[tx][ty]) dfs2(tx, ty);
			}
			else
				ans[f[tx][ty]] = true;
		}
	}
}

int main()
{
	freopen("pic.in", "r", stdin);
	freopen("pic.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", a[i] + 1);
		a[i][0] = a[i][m + 1] = '0';
	}
	n += 2;
	m += 2;
	for (int i = 0; i < m; ++i) a[0][i] = a[n - 1][i] = '0';
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (!f[i][j]) ++cnt, dfs1(i, j);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j) printf("%c", '!' + f[i][j]);
		puts("");
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (a[i][j] == '1' && !vis[i][j])
			{
				int an = 0;
				memset(ans, 0, sizeof ans);
				dfs2(i, j);
				for (int k = 1; k <= cnt; ++k) an += ans[k];
				printf("%c ", '!' + f[i][j]);
				putchar(t[an - 1]);
				puts("");
			}
	return 0;
}