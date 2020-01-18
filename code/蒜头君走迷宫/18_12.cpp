#include <algorithm>
#include <cstdio>

using std::max;

typedef long long ll;
const int N = 100000, D = 1E9 + 7;
ll inv[N + 1], sum_inv[N + 1];

ll fact(int n)
{
	ll ret = 1;
	for (int i = 2; i <= n; ++i) ret = ret * i % D;
	return ret;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int s = max(n, m) - 1;
	inv[1] = sum_inv[1] = 1;
	for (int i = 2; i <= s; ++i)
	{
		inv[i] = (D - D / i) * inv[D % i] % D;
		sum_inv[i] = inv[i] * sum_inv[i - 1] % D;
	}
	ll ans = fact(n + m - 2) * sum_inv[n - 1] % D
			 * sum_inv[m - 1] % D;
	printf("%lld", ans);
	return 0;
}