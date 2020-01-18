// AC
#include <cstdio>

int main()
{
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			int a;
			scanf("%d", &a);
			if (!i || !j || i == n - 1 || j == m - 1) ans += a;
		}
	printf("%d", ans);
	return 0;
}