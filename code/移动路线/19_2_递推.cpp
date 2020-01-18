// AC
#include <cstdio>

const int N = 20;
long long f[N][N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	f[0][0] = 1;
	for (int i = 1; i < n; ++i) f[i][0] = 1;
	for (int i = 1; i < m; ++i) f[0][i] = 1;
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < m; ++j) f[i][j] = f[i - 1][j] + f[i][j - 1];
	printf("%lld", f[n - 1][m - 1]);
	return 0;
}