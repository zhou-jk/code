#include <algorithm>
#include <cstdio>
#include <cstdlib>

using std::max;

const int N = 1000;
int a[N], b[N], n, m, ans = 1E9;
bool vis[N];

void dfs(int k, int t)
{
	if (t + abs(k - m) >= ans) return;
	bool flag = true;
	for (int i = 0; i < n; ++i)
		if (!vis[i])
		{
			flag = false;
			int tmp = max(t + abs(k - a[i]), b[i]);
			vis[i] = true;
			dfs(a[i], tmp);
			vis[i] = false;
		}
	if (flag) ans = t + abs(k - m);
}

int main()
{
	freopen("broken.in", "r", stdin);
	freopen("broken.out", "w", stdout);
	int x;
	scanf("%d%d%d", &n, &x, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", a + i, b + i);
		if (!a[i] && !b[i]) vis[i] = true;
	}
	dfs(0, 0);
	printf("%d", ans);
	return 0;
}