// AC
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using std::min;

typedef long long ll;

const int N = 20;
int a[N], n, m;
ll ans = 1e14;

void dfs(int k, ll s)
{
	if (s >= m)
	{
		ans = min(ans, s);
		if (ans == m)
		{
			printf("%lld", ans);
			exit(0);
		}
		return;
	}
	if (k >= n) return;
	ll tmp = 1;
	dfs(k + 1, s);
	while (tmp * s < m) tmp *= a[k], dfs(k + 1, s * tmp);
}

int main()
{
	freopen("num.in", "r", stdin);
	freopen("num.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	dfs(0, 1);
	printf("%lld", ans);
	return 0;
}