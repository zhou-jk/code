// AC
#include <cmath>
#include <cstdio>

bool check(int num)
{
	if (num < 2) return false;
	int m = sqrt(num);
	for (int i = 2; i <= m; ++i)
		if (!(num % i)) return false;
	return true;
}

int main()
{
	int l, r, ans = 0;
	scanf("%d%d", &l, &r);
	for (int i = l; i <= r; ++i) ans += check(i);
	printf("%d", ans);
	return 0;
}