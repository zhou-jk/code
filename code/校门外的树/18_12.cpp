// AC
#include <cstdio>

const int N = 10000;
bool f[N];

int main()
{
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		for (int j = l; j <= r; ++j) f[j] = true;
	}
	for (int i = 0; i <= n; ++i) ans += !f[i];
	printf("%d", ans);
	return 0;
}
