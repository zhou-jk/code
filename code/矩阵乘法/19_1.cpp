// AC
#include <cstdio>

const int N = 100;
int a[N][N], b[N][N], c[N][N];

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < k; ++j) scanf("%d", &b[i][j]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < k; ++j)
			for (int p = 0; p < m; ++p) c[i][j] += a[i][p] * b[p][j];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < k; ++j) printf("%d ", c[i][j]);
		putchar('\n');
	}
	return 0;
}