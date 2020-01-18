// AC
#include <algorithm>
#include <cstdio>

using std::max;

const int N = 1000;
int a[N], f[N], g[N];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
		for (int j = 0; j < i; ++j) f[i] = max(f[i], a[j] < a[i] ? f[j] : 0);
		++f[i];
	}
	for (int i = n - 1; ~i; --i)
	{
		for (int j = n - 1; j > i; --j)
			g[i] = max(g[i], a[j] < a[i] ? g[j] : 0);
		++g[i];
		ans = max(ans, f[i] + g[i] - 1);
	}
	printf("%d", ans);
	return 0;
}