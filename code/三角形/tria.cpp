#include <cstdio>

const int N = 22;
int s[N + 1];

int main()
{
	freopen("tria.in", "r", stdin);
	freopen("tria.out", "w", stdout);
	int n, ans = 0;
	scanf("%d", &n);
	if (((n + 1) * n >> 1) & 1)
	{
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; ++i) s[i] = (i * (i + 1)) >> 1;
	for (int i = 0; i < 1 << n; ++i)
	{
		int cnt = 0, x1 = i;
		for (int j = n; j; --j)
		{
			if (cnt > s[j] || cnt < -s[j]) break;
			int x2 = x1;
			while (x2)
			{
				cnt += 2;
				x2 &= x2 - 1;
			}
			cnt -= j;
			x1 = (x1 ^ (x1 >> 1)) & ((1 << (j - 1)) - 1);
		}
		if (!cnt) ++ans;
	}
	printf("%d", ans);
	return 0;
}