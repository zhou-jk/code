// AC
#include <algorithm>
#include <cstdio>

using std::max;

typedef long long ll;

const int N = 55;
ll a[N], n, m;

bool check(ll x)
{
	ll sum = 0;
	for (int i = 0; i < n; ++i)
		if (x > a[i]) sum += x - a[i];
	if (sum > m || sum > x) return false;
	return true;
}

int main()
{
	freopen("be.in", "r", stdin);
	freopen("be.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	ll l = 0, r = 0;
	for (int i = 0; i < n; ++i) scanf("%lld", a + i), r = max(r, a[i]);
	r += m;
	while (l <= r)
	{
		ll mid = (l + r) >> 1;
		if (check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	printf("%lld", r);
	return 0;
}