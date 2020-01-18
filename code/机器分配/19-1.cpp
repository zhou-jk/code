// AC
#include <algorithm>
#include <cstdio>

using std::max;

const int N = 10, M = 15;
int w[M], f[N + 1][M + 1], g[N + 1][M + 1], a[N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < m; ++j) scanf("%d", w + j);
		for (int j = 1; j <= m; ++j)
		{
			f[i][j] = f[i - 1][j];
			for (int k = j - 1; ~k; --k)
				if (f[i - 1][j - k - 1] + w[k] > f[i][j])
					f[i][j] = f[i - 1][j - k - 1] + w[k], g[i][j] = k + 1;
		}
	}
	printf("%d\n", f[n][m]);
	for (int i = n - 1; ~i; --i)
	{
		a[i] = g[i + 1][m];
		m -= g[i + 1][m];
	}
	for (int i = 0; i < n; ++i) printf("%d %d\n", i + 1, a[i]);
	return 0;
}