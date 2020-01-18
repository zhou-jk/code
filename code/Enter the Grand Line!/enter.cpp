// AC
#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int ma[N << 1][N << 1];

int main()
{
	freopen("enter.in", "r", stdin);
	freopen("enter.out", "w", stdout);
	int n, m, ans = -1E9;
	scanf("%d", &n);
	m = n << 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &ma[i][j]);
			ans = max(ans, ma[i][j]);
			ma[i + n][j] = ma[i][j + n] = ma[i + n][j + n] = ma[i][j];
		}
	if (ans <= 0)
	{
		printf("%d", ans);
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, tmp1 = 0,
			tmp2 = 0, tmp3 = 0, tmp4 = 0, sum1 = 0, sum2 = 0, sum3 = 0,
			sum4 = 0;
		for (int j = 0; j < n; ++j)
		{
			sum1 += ma[i][j];
			a += ma[i][j];
			if (a < 0) a = 0;
			sum2 += ma[j][i];
			b += ma[j][i];
			if (b < 0) b = 0;
			c += ma[i][j];
			if (c > 0) c = 0;
			tmp1 = min(tmp1, c);
			d += ma[j][i];
			if (d > 0) d = 0;
			tmp2 = min(tmp2, d);
			sum3 += ma[i + j][j];
			e += ma[i + j][j];
			if (e < 0) e = 0;
			sum4 += ma[j][i + j];
			f += ma[j][i + j];
			if (f < 0) f = 0;
			g += ma[i + j][j];
			if (g > 0) g = 0;
			tmp3 = min(tmp3, g);
			h += ma[j][i + j];
			if (h > 0) h = 0;
			tmp4 = min(tmp4, h);
			ans = max(ans, max(max(a, b), max(e, f)));
		}
		ans = max(ans, max(max(sum1 - tmp1, sum2 - tmp2),
						   max(sum3 - tmp3, sum4 - tmp4)));
	}
	for (int i = n - 1; i < m - 1; ++i)
	{
		int a = 0, b = 0, tmp = 0, sum = 0;
		for (int j = 0; j < n; ++j)
		{
			sum += ma[i - j][j];
			a += ma[i - j][j];
			if (a < 0) a = 0;
			b += ma[i - j][j];
			if (b > 0) b = 0;
			tmp = min(tmp, b);
			ans = max(ans, a);
		}
		ans = max(ans, sum - tmp);
	}
	printf("%d", ans);
	return 0;
}