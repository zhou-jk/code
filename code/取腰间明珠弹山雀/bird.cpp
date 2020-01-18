// AC
#include <algorithm>
#include <cstdio>

using std::max;
using std::sort;

const int N = 2000;
int a[N], f[N];

int main()
{
	freopen("bird.in", "r", stdin);
	freopen("bird.out", "w", stdout);
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j) f[i] = max(f[i], a[i] % a[j] ? 0 : f[j]);
		++f[i];
		ans = max(ans, f[i]);
	}
	printf("%d", ans);
	return 0;
}