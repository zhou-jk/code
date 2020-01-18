#include <algorithm>
#include <cstdio>

using std::max;
using std::sort;

const int N = 2000;
int a[N], f[N], n, cnt, ans;

void dfs(int k)
{
	if (cnt + n - k <= ans) return;
	if (k == n)
	{
		for (int i = 0; i < cnt; ++i)
			for (int j = 0; j < cnt; ++j)
				if (f[i] % f[j] && f[j] % f[i]) return;
		ans = cnt;
		return;
	}
	dfs(k + 1);
	f[cnt++] = a[k];
	dfs(k + 1);
	--cnt;
}

int main()
{
	freopen("bird.in", "r", stdin);
	freopen("bird_duipai.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	dfs(0);
	printf("%d", ans);
	return 0;
}