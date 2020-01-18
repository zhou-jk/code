// AC
#include <cmath>
#include <cstdio>

typedef long long ll;

bool is_prime(ll num)
{
	int m = sqrt(num);
	for (int i = 2; i <= m; ++i)
		if (!(num % i)) return false;
	return true;
}

int main()
{
	freopen("snow.in", "r", stdin);
	freopen("snow.out", "w", stdout);
	ll n;
	scanf("%lld", &n);
	if (n & 1)
	{
		if (is_prime(n))
			puts("1");
		else if (is_prime(n - 2))
			puts("2");
		else
			puts("3");
	}
	else if (n == 2)
		puts("1");
	else
		puts("2");
	return 0;
}