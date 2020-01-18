// AC
#include <cstdio>

const int N = 100;
int a[N][N];

int main()
{
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			int tmp;
			scanf("%d", &tmp);
			ans += tmp == a[i][j];
		}
	printf("%.2lf", (double)ans / (n * m) * 100);
	return 0;
}