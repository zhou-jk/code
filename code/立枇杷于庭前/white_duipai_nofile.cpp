#include <cstdio>

const int N = 1000, M = 500000;
int a[N], n, ans;

void dfs(int k, int s)
{
	if (k == n)
	{
		ans ^= s;
		return;
	}
	dfs(k + 1, s);
	dfs(k + 1, s + a[k]);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	dfs(0, 0);
	printf("%d", ans);
	return 0;
}