// AC
#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;
using std::sort;
using std::unique;

const int N = 100, A = 100;
int a[N], f[A * A];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n);
	n = unique(a, a + n) - a;
	int m1 = min(m, a[n - 1] * a[n - 1] - 1);
	memset(f, 63, sizeof f);
	f[0] = 0;
	for (int i = 0; i < n - 1; ++i)
		for (int j = a[i]; j <= m1; ++j) f[j] = min(f[j], f[j - a[i]] + 1);
	int ans = m + 1;
	for (int i = 0; i <= m1; ++i)
		if (!((m - i) % a[n - 1])) ans = min(ans, f[i] + (m - i) / a[n - 1]);
	printf("%d", ans > m ? -1 : ans);
	return 0;
}