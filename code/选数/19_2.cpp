#include <cmath>
#include <cstdio>

const int N = 20;
int a[N], n, ans;

bool check(int n)
{
	if (n < 2) return false;
	int m = sqrt(n);
	for (int i = 2; i <= m; ++i)
		if (!(n % i)) return false;
	return true;
}

void dfs(int m, int sum, int l)
{
	if (n - l < m) return;
	if (!m)
	{
		ans += check(sum);
		return;
	}
	for (int i = l; i < n; ++i) dfs(m - 1, sum + a[i], i + 1);
}

int main()
{
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	dfs(m, 0, 0);
	printf("%d", ans);
	return 0;
}