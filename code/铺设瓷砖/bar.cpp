// AC
#include <cstdio>

typedef long long ll;
const int N = 2 << 10, NN = (N * N - 1) / 3;
int map[N][N], h[NN], cnt, cnth;

void solve(int x1, int y1, int x2, int y2, int x, int y)
{
	if (x2 - x1 == 1)
	{
		for (int i = x1; i <= x2; ++i)
			for (int j = y1; j <= y2; ++j)
				if (i != x || y != j) map[i][j] = cnt;
		++cnt;
		return;
	}
	int midx = (x1 + x2) >> 1, midy = (y1 + y2) >> 1;
	int cnt1 = cnt++;
	if (x <= midx && y <= midy)
		solve(x1, y1, midx, midy, x, y);
	else
		solve(x1, y1, midx, midy, midx, midy), map[midx][midy] = cnt1;
	if (x <= midx && y > midy)
		solve(x1, midy + 1, midx, y2, x, y);
	else
		solve(x1, midy + 1, midx, y2, midx, midy + 1),
			map[midx][midy + 1] = cnt1;
	if (x > midx && y <= midy)
		solve(midx + 1, y1, x2, midy, x, y);
	else
		solve(midx + 1, y1, x2, midy, midx + 1, midy),
			map[midx + 1][midy] = cnt1;
	if (x > midx && y > midy)
		solve(midx + 1, midy + 1, x2, y2, x, y);
	else
		solve(midx + 1, midy + 1, x2, y2, midx + 1, midy + 1),
			map[midx + 1][midy + 1] = cnt1;
}

int main()
{
	freopen("bar.in", "r", stdin);
	freopen("bar.out", "w", stdout);
	int n, x, y;
	ll ans = 0;
	scanf("%d%d%d", &n, &x, &y);
	n = 1 << n;
	map[x - 1][y - 1] = -1;
	solve(0, 0, n - 1, n - 1, x - 1, y - 1);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			// printf("%d ", map[i][j]);
			if (map[i][j] > -1)
			{
				if (!h[map[i][j]]) h[map[i][j]] = ++cnth;
				ans += (ll)(i + 1) * (j + 1) * h[map[i][j]];
			}
		}
		// puts("");
	}
	printf("%lld", ans);
	return 0;
}