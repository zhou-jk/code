// AC
#include <cstdio>

const int N = 10, M = 10;
int f[N + 1][M + 1];

int dfs(int n, int m)
{
	if (f[n][m]) return f[n][m];
	if (!n) return 1;
	if (m == 1) return 1;
	return f[n][m] = n < m ? dfs(n, n) : dfs(n, m - 1) + dfs(n - m, m);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%d\n", dfs(n, m));
	}
	return 0;
}