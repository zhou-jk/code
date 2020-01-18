// AC
#include <algorithm>
#include <cstdio>

using std::sort;

const int N = 100000, M = 50, D = 1E9 + 7;
int p[N], c[N][M];

int main()
{
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
	sort(p, p + n);
	c[0][0] = 1;
	for (int i = 1; i < n; ++i)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i && j < m; ++j)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % D;
	}
	for (int i = m - 1; i < n; ++i)
		ans = (ans + (long long)c[i][m - 1] * p[i] % D) % D;
	printf("%d", ans);
	return 0;
}