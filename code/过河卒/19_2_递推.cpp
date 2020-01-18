// AC
#include <cstdio>

const int N = 20 + 1, N_DIR = 8, dx[N_DIR] = {-1, -1, -2, -2, 1, 1, 2, 2},
		  dy[N_DIR] = {-2, 2, -1, 1, -2, 2, -1, 1};
long long f[N][N];

int main()
{
	int n, m, x, y;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	if (x >= 0 && x <= n && y >= 0 && y <= m) f[x][y] = -1;
	for (int i = 0; i < N_DIR; ++i)
	{
		int tx = x + dx[i], ty = y + dy[i];
		if (tx >= 0 && tx <= n && ty >= 0 && ty <= m) f[tx][ty] = -1;
	}
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i) f[i][0] = f[i][0] == -1 ? 0 : f[i - 1][0];
	for (int i = 1; i <= m; ++i) f[0][i] = f[0][i] == -1 ? 0 : f[0][i - 1];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			f[i][j] = f[i][j] == -1 ? 0 : f[i - 1][j] + f[i][j - 1];
	printf("%lld", f[n][m]);
	return 0;
}