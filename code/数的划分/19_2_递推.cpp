// AC
#include <cstdio>

const int N = 200, M = 6;
int f[N + 1][M + 1];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) f[i][1] = 1;
	for (int i = 2; i <= n; ++i)
		for (int j = 2; j <= m && j <= i; ++j)
			f[i][j] = f[i - 1][j - 1] + f[i - j][j];
	printf("%d\n", f[n][m]);
	return 0;
}