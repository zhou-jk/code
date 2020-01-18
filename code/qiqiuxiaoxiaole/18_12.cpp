#include <cstdio>

typedef long long ll;

const ll D = 1E9 + 7;

ll pow(ll a, ll b)
{
	if (!b) return 1;
	ll tmp = pow(a, b >> 1);
	tmp = tmp * tmp % D;
	// printf("%lld\n", tmp);
	if (b & 1) tmp = tmp * a % D;
	// printf("#%lld %lld %lld\n", a, b, tmp);
	return tmp;
}

int main()
{
	ll n, m;
	scanf("%lld%lld", &n, &m);
	// printf("%lld %lld %lld %lld\n", n, m, pow(m, n - 1),pow(m
	// - 1, n - 1));
	printf("%lld", (pow(m, n - 1) - pow(m - 1, n - 1)) * m % D);
	return 0;
}