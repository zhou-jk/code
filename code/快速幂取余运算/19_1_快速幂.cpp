// AC
#include <cstdio>

typedef long long ll;

ll pow(ll a, ll b, ll p)
{
	ll ret = 1 % p; //可能%1
	a %= p;
	for (; b; b >>= 1)
	{
		if (b & 1) ret = ret * a % p;
		a = a * a % p;
	}
	return ret;
}

int main()
{
	ll a, b, p;
	scanf("%lld%lld%lld", &a, &b, &p);
	printf("%lld^%lld mod %lld=%lld", a, b, p, pow(a, b, p));
	return 0;
}