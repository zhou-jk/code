#include <algorithm>
#include <cmath>
#include <cstdio>

using std::abs;
using std::swap;

long long exgcd(long long a, long long b, long long &x,
				long long &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long ret = exgcd(b, a % b, x, y);
	long long t = x;
	x = y;
	y = t - a / b * y;
	return ret;
}

int main()
{
	long long x, y, m, n, l;
	scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l);
	long long a = m - n, c = y - x;
	long long s1, s2;
	long long d = exgcd(a, l, s1, s2);
	d = abs(d);
	// printf("%lld %lld\n", d, s1);
	if (!(c % d))
	{
		s1 *= c / d;
		long long tmp = l / d;
		// printf("%lld %lld\n", s1, tmp);
		s1 = (s1 % tmp + tmp) % tmp;
		printf("%lld", s1);
	}
	else
		puts("Impossible");
	return 0;
}