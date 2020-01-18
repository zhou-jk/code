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
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int tmp;
			scanf("%d", &tmp);
			printf("%d ", a[i][j] + tmp);
		}
		putchar('\n');
	}
	return 0;
}