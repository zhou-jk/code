// AC
#include <cmath>
#include <cstdio>

int solve(int n)
{
	int m = sqrt(n), ret;
	for (int i = 2; i <= m; ++i)
		if (!(n % i))
		{
			ret = i;
			while (!(n % i)) n /= i;
		}
	if (n > 1) ret = n;
	return ret;
}

int main()
{
	int l, r;
	scanf("%d%d", &l, &r);
	for (int i = l; i < r; ++i) printf("%d,", solve(i));
	printf("%d", solve(r));
	return 0;
}