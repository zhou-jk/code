// AC
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using std::min;

const int N = 2500;
int a[N + 1], f[N + 1];

int main()
{
	freopen("soul.in", "r", stdin);
	freopen("soul.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	memset(f, 63, sizeof f);
	f[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		int tmp = 0;
		scanf("%d", &a[i]);
		for (int j = i; j; --j)
		{
			tmp += a[j] == 2 ? 1 : -1;
			int tmp1 = abs(tmp);
			if (tmp1 <= m || tmp1 == i - j + 1) f[i] = min(f[i], f[j - 1] + 1);
		}
	}
	printf("%d", f[n]);
	return 0;
}