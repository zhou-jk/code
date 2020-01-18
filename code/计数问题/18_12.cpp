// AC
#include <cstdio>

int main()
{
	int n, x, ans = 0;
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++i)
		for (int j = i; j; j /= 10)
			if (j % 10 == x) ++ans;
	printf("%d", ans);
	return 0;
}