// AC
#include <cstdio>

int main()
{
	int x, n, ans = 0;
	scanf("%d%d", &x, &n);
	if (x < 6) ans = (6 - x) * 250;
	n -= 7 - x + 1;
	ans += (n - n / 7 * 2) * 250;
	if (n % 7 > 5) ans -= 250;
	printf("%d", ans);
	return 0;
}