// AC
#include <cstdio>

const int N = 30;
long long f[N + 1][N + 1];

void dfs(int n, int m)
{
	if (f[n][m]) return;
	if (n == m || m == 1)
	{
		f[n][m] = 1;
		return;
	}
	dfs(n - 1, m);
	dfs(n - 1, m - 1);
	f[n][m] = f[n - 1][m] * m + f[n - 1][m - 1];
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	dfs(n, m);
	printf("%lld", f[n][m]);
	return 0;
}