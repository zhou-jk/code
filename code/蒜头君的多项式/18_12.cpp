#include <cstdio>

const int D = 10007, K = 1000;

int c[K + 1][K + 1];

int pow(int a, int b)
{
	if (!b) return 1;
	int tmp = pow(a, b >> 1);
	tmp = tmp * tmp % D;
	if (b & 1) tmp = tmp * a % D;
	return tmp;
}

int main()
{
	int p, q, k, a, b;
	scanf("%d%d%d%d%d", &p, &q, &k, &a, &b);
	c[0][0] = 1;
	for (int i = 1; i <= k; ++i)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j)
		{
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % D;
			// printf("#%d %d %d\n", i, j, c[i][j]);
		}
	}
	// printf("%d %d %d\n", pow(p, a), pow(q, b), c[k][a]);
	printf("%d",
		   pow(p % D, a) * pow(q % D, b) % D * c[k][a] % D);
	return 0;
}