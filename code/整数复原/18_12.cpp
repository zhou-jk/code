#include <cstdio>

typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll ret = exgcd(b, a % b, x, y);
	ll tmp = x;
	x = y;
	y = tmp - a / b * y;
	return ret;
}

int main()
{
	int n;
	ll a0, r0;
	scanf("%d%lld%lld", &n, &a0, &r0);
	for (int i = 1; i < n; ++i)
	{
		ll a, r, x, y;
		scanf("%lld%lld", &a, &r);
		// printf("#%d %d\n", a, r);
		ll d = exgcd(a0, a, x, y);
		ll b = r0 - r;
		// printf("$%d %d\n", b, d);
		if (b % d)
		{
			puts("-1");
			return 0;
		}
		ll tmp = a / d, tmp1 = a0 * a / d;
		// printf("%d\n", x);
		x *= b / d;
		x = (x % tmp + tmp) % tmp;
		r0 = (r0 - x * a0) % tmp1;
		a0 = tmp1;
		// printf("%d %d %d\n", x, r0, a0);
	}
	if (r0 < 0) r0 += a0;
	printf("%lld", r0);
	return 0;
}