// AC
#include <algorithm>
#include <cstdio>

using std::max;

const int N = 1000;
int a[N], f[N];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
		for (int j = 0; j < i; ++j) f[i] = max(f[i], a[j] < a[i] ? f[j] : 0);
		f[i] += a[i];
		ans = max(ans, f[i]);
	}
	printf("%d", ans);
	return 0;
}