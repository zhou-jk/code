// AC
#include <cmath>
#include <cstdio>

typedef long long ll;

const ll P = 1E9 + 7;

ll euler(ll num)
{
	int m = sqrt(num);
	ll ret = num;
	for (int i = 2; i <= m; ++i)
		if (!(num % i))
		{
			ret -= ret / i;
			while (!(num % i)) num /= i;
		}
	if (num > 1) ret -= ret / num;
	return ret;
}

ll pow(ll a, ll b)
{
	ll ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % P;
		a = a * a % P;
		b >>= 1;
	}
	return ret;
}

int main()
{
	ll n, k, a, b;
	scanf("%lld%lld%lld%lld", &n, &k, &a, &b);
	ll t = euler(n);
	ll ans = (a + b) % P * pow(k % P, (ll)n * (t >> 1)) % P;
	printf("%lld", ans);
	return 0;
}
