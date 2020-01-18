// AC
#include <cstdio>

const int N = 3000, P = 1000000007;
int c[N + 1][N + 1], s[(N * N >> 2) + 1], f[N + 1];

int main()
{
	freopen("confused.in", "r", stdin);
	freopen("confused.out", "w", stdout);
	int n;
	scanf("%d", &n);
	c[0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % P;
	}
	s[0] = 1;
	int tmp = (n >> 1) * (n - (n >> 1));
	for (int i = 1; i <= tmp; ++i) s[i] = (s[i - 1] << 1) % P;
	f[0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			f[i] = ((f[i]
					 + (long long)(j & 1 ? 1 : -1) * c[i][j] * s[j * (i - j)]
						   % P * f[i - j])
						% P
					+ P)
				   % P;
	printf("%d", f[n]);
	return 0;
}