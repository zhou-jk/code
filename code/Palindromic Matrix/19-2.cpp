#include <cstdio>

const int N = 20, MAX = 1000;
int vis[MAX + 1], ans[N][N], cnt[2];

int main()
{
	int n, a, x = 0, y = 0, c = 0, d = 0;
	scanf("%d", &n);
	for (int i = 0; i < n * n; ++i)
	{
		scanf("%d", &a);
		++vis[a];
	}
	for (int i = 1; i <= MAX; ++i)
	{
		if (vis[i] & 2) ++cnt[0];
		if (vis[i] & 1)
		{
			ans[n >> 1][n >> 1] = i;
			--vis[i];
			++cnt[1];
		}
		if (((n & 1) && cnt[0] >= n) || (!(n & 1) && cnt[0])
			|| cnt[1] > (n & 1))
		{
			puts("NO");
			return 0;
		}
		while (x<n>> 1 && vis[i] >= 4)
		{
			ans[x][y] = ans[x][n - 1 - y] = ans[n - 1 - x][y] =
				ans[n - 1 - x][n - 1 - y] = i;
			vis[i] -= 4;
			x += (y + 1) / (n >> 1);
			y = (y + 1) % (n >> 1);
		}
		while (c<n>> 1 && vis[i] >= 2)
		{
			ans[c][n >> 1] = ans[n - 1 - c][n >> 1] = i;
			vis[i] -= 2;
			++c;
		}
		while (d<n>> 1 && vis[i] >= 2)
		{
			ans[n >> 1][d] = ans[n >> 1][n - 1 - d] = i;
			vis[i] -= 2;
			++d;
		}
	}
	puts("YES");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j) printf("%d ", ans[i][j]);
		putchar('\n');
	}
	return 0;
}