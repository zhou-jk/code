// AC
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using std::sort;

typedef long long ll;

const int N = 100000;
int x[N], y[N], bx[N], by[N], dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int main()
{
	freopen("center.in", "r", stdin);
	freopen("center.out", "w", stdout);
	int n;
	ll ans;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d%d", x + i, y + i);
	memcpy(bx, x, n * sizeof x[0]);
	memcpy(by, y, n * sizeof y[0]);
	sort(x, x + n);
	sort(y, y + n);
	if (n & 1)
	{
		int tx = x[n >> 1], ty = y[n >> 1];
		for (int i = 0; i < n; ++i)
			if (bx[i] == tx && by[i] == ty)
			{
				ans = 1e16;
				ll s;
				for (int j = 0; j < 4; ++j)
				{
					int ttx = tx + dx[j], tty = tx + dy[j];
					ll an = 0;
					for (int k = 0; k < n; ++k)
						an += abs(x[k] - ttx) + abs(y[k] - tty);
					if (an < ans)
					{
						ans = an;
						s = 0;
					}
					s += ans == an;
				}
				printf("%lld %lld", ans, s);
				return 0;
			}
		ans = 0;
		for (int i = 0; i<n>> 1; ++i)
			ans += x[n - 1 - i] - x[i] + y[n - 1 - i] - y[i];
		printf("%lld 1", ans);
	}
	else
	{
		ans = 0;
		for (int i = 0; i<n>> 1; ++i)
			ans += x[n - 1 - i] - x[i] + y[n - 1 - i] - y[i];
		int s = 0, tx1 = x[n >> 1], tx2 = x[(n >> 1) - 1], ty1 = y[n >> 1],
			ty2 = y[(n >> 1) - 1];
		for (int i = 0; i < n; ++i)
			if ((bx[i] == tx1 || bx[i] == tx2)
				&& (by[i] == ty1 || by[i] == ty2))
				++s;
		printf("%lld %lld", ans, (ll)(tx1 - tx2 + 1) * (ty1 - ty2 + 1) - s);
	}
	return 0;
}