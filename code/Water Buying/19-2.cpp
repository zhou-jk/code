#include <cstdio>

int main()
{
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int a, b;
		long long n, ans = 0;
		scanf("%I64d%d%d", &n, &a, &b);
		if (b < a << 1)
		{
			ans += (n >> 1) * b;
			n &= 1;
		}
		ans += n * a;
		printf("%I64d\n", ans);
	}
	return 0;
}