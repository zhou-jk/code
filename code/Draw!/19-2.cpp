#include <algorithm>
#include <cstdio>

using std::max;
using std::min;

int main()
{
	int n, a = 0, b = 0, ans = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int ca, cb;
		scanf("%d%d", &ca, &cb);
		int tmp = min(ca, cb) - max(a, b) + 1;
		if (a == b) --tmp;
		tmp = max(tmp, 0);
		ans += tmp;
		a = ca, b = cb;
	}
	printf("%d", ans);
	return 0;
}