// AC
#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;

typedef long long ll;

const int N = 15;
int f[1 << N];
bool a[N][N], tmp[N][N];

int main()
{
	freopen("die.in", "r", stdin);
	freopen("die.out", "w", stdout);
	int n, m, ans = 1E7;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			int tmp;
			scanf("%d", &tmp);
			a[i][j] = tmp;
		}
	for (int i = 1; i < 1 << m; ++i) f[i] = f[i - (i & -i)] + 1;
	for (int i = 0; i < 1 << m; ++i)
	{
		ll tmp1 = i;
		int sum = f[i];
		memcpy(tmp, a, sizeof a);
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
				if (tmp1 & (1 << k))
				{
					tmp[j][k] = !tmp[j][k];
					if (j) tmp[j - 1][k] = !tmp[j - 1][k];
					if (j < n - 1) tmp[j + 1][k] = !tmp[j + 1][k];
					if (k) tmp[j][k - 1] = !tmp[j][k - 1];
					if (k < m - 1) tmp[j][k + 1] = !tmp[j][k + 1];
				}
			tmp1 = 0;
			for (int k = 0; k < m; ++k) tmp1 ^= tmp[j][k] << k;
			sum += f[tmp1];
		}
		if (!tmp1) ans = min(ans, sum);
	}
	printf("%d", ans == 1E7 ? -1 : ans);
	return 0;
}