// AC
#include <cstdio>

const int N = 200;
int a[N], f[N], s[N], g[N][N];

int main()
{
	int n, ans = 0, k;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	while (true)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		if (!u && !v) break;
		--u;
		--v;
		g[u][++g[u][0]] = v;
	}
	for (int i = n - 1; ~i; --i)
	{
		s[i] = i;
		for (int j = 1; j <= g[i][0]; ++j)
			if (f[g[i][j]] > f[i]) f[i] = f[g[i][j]], s[i] = g[i][j];
		f[i] += a[i];
		if (f[i] > ans) ans = f[i], k = i;
	}
	printf("%d", k + 1);
	while (s[k] != k)
	{
		k = s[k];
		printf("-%d", k + 1);
	}
	putchar('\n');
	printf("%d", ans);
	return 0;
}