// AC
#include <cstdio>

const int N = 10, M = 10;
int f[N + 1][M + 1];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) f[i][1] = 1;
		for (int i = 1; i <= m; ++i) f[0][i] = 1;
		for (int i = 1; i <= n; ++i)
			for (int j = 2; j <= m; ++j)
				f[i][j] = i < j ? f[i][i] : f[i][j - 1] + f[i - j][j];
		printf("%d\n", f[n][m]);
	}
	return 0;
}