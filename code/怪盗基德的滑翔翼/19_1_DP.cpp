// AC
#include <algorithm>
#include <cstdio>

using std::max;

const int N = 100;
int a[N], f[N], g[N];

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		int n, ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", a + i);
			f[i] = g[i] = 0;
			for (int j = 0; j < i; ++j)
			{
				f[i] = max(f[i], a[j] > a[i] ? f[j] : 0);
				g[i] = max(g[i], a[j] < a[i] ? g[j] : 0);
			}
			++f[i];
			++g[i];
			ans = max(ans, max(f[i], g[i]));
		}
		printf("%d\n", ans);
	}
	return 0;
}