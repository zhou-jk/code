// AC
#include <cstdio>

const int N = 71;
long long f[N + 1];

int main()
{
	int n, k = 3;
	f[0] = f[1] = 1;
	f[2] = 2;
	while (scanf("%d", &n) != EOF && n)
	{
		for (; k <= n; ++k) f[k] = f[k - 1] + f[k - 2] + f[k - 3];
		printf("%lld\n", f[n]);
	}
	return 0;
}