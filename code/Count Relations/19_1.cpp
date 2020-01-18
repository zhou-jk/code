// AC
#include <cstdio>

typedef long long ll;

const ll P = 100000007;

ll pow(ll a, ll b)
{
	ll ret = 1 % P;
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
	int n;
	scanf("%d", &n);
	ll inv = pow(2, P - 2);
	for (int i = 0; i < n; ++i)
	{
		ll a;
		scanf("%lld", &a);
		printf("%lld %lld\n",
			   ((pow(3, a) - pow(2, a + 1) + 1) % P + P) * inv % P,
			   ((pow(4, a) - pow(3, a + 1) + 3 * pow(2, a) - 1) % P + P) % P
				   * inv % P);
	}
	return 0;
}