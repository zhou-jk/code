// AC
#include <cstdio>

const int N = 1000000, P = 32767;
int f[N];

int main()
{
	int t, k = 2;
	f[0] = 1;
	f[1] = 2;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (; k < n; ++k) f[k] = (2 * f[k - 1] + f[k - 2]) % P;
		printf("%d\n", f[n - 1]);
	}
	return 0;
}