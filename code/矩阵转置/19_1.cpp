// AC
#include <cstdio>

const int N = 100;
int a[N][N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j) printf("%d ", a[j][i]);
		putchar('\n');
	}
	return 0;
}