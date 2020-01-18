// AC
#include <algorithm>
#include <cstdio>

using std::max;
using std::swap;

typedef long long ll;

const int M = 2e6;
ll s1[M], s2[M + 1], n, m, seed, l, r, x, y;

ll rnd()
{
	seed ^= seed << 26;
	seed ^= seed >> 14;
	seed ^= seed << 19;
	if (seed < 0) seed = -seed;
	return seed;
}

void readData()
{
	l = rnd() % m + 1;
	r = rnd() % m + 1;
	if (l > r) swap(l, r);
	if (l == m) l--;
	if (l == r) r++;
	if (rnd() % 3 == 0)
	{
		x = rnd() % m + 1;
		y = rnd() % m + x;
		y -= (y - x) % (r - l);
		if (x == y) y += r - l;
	}
	else
	{
		x = rnd() % m + 1;
		y = x + (1 + rnd() % 1000) * (r - l);
	}
}

int main()
{
	freopen("list.in", "r", stdin);
	freopen("list.out", "w", stdout);
	ll ans = 0, an = 0, tmp = 0;
	scanf("%lld%lld%lld", &n, &m, &seed);
	for (int i = 0; i < n; ++i)
	{
		readData();
		// printf("%lld %lld %lld %lld\n", l, r, x, y);
		--l;
		--r;
		s1[l] += (y - x) / (r - l);
		s2[l] += x;
		s1[r] -= (y - x) / (r - l);
		s2[r + 1] -= y;
	}
	for (int i = 0; i < m; ++i)
	{
		an += s2[i] + tmp;
		ans = max(ans, an);
		tmp += s1[i];
	}
	printf("%lld", ans);
	return 0;
}