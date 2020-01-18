// AC
#include <cmath>
#include <cstdio>

const int N = 100;
int a[N][N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			printf("%d ", !i || !j || i == n - 1 || j == m - 1 ?
							  a[i][j] :
							  (int)round((a[i][j] + a[i][j - 1] + a[i - 1][j]
										  + a[i][j + 1] + a[i + 1][j])
										 / 5.0));
		putchar('\n');
	}
	return 0;
}