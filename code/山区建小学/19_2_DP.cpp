// AC
#include <algorithm>
#include <cstdio>

using std::min;

const int N = 500;
int sum[N], f[N][N], g[N][N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		sum[i] = sum[i - 1] + tmp;
	}
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			g[i][j] = g[i][j - 1] + sum[j] - sum[(i + j) >> 1];
	for (int i = 0; i < n; ++i) f[i][0] = g[0][i];
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < m && j <= i; ++j)
		{
			f[i][j] = 1E9;
			for (int k = 0; k < i; ++k)
				f[i][j] = min(f[i][j], f[k][j - 1] + g[k + 1][i]);
		}
	printf("%d", f[n - 1][m - 1]);
	return 0;
}