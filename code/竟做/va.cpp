// AC
#include <algorithm>
#include <cstdio>

using std::swap;

const int N = 100000;
int ans[N], type, k, seed;

int random()
{
	return seed = (long long)seed * 48271 % 2147483647;
}

int get(int l, int r)
{
	switch (type)
	{
		case 1: return l;
		case 2: return r;
		case 3: return (l + r) >> 1;
		case 4: return random() % (r - l + 1) + l;
		default: return -1;
	}
}

void solve(int l, int r)
{
	int x = get(l, r);
	if (l + 1 < r) solve(l + 1, r);
	swap(ans[l], ans[x]);
}

int main()
{
	freopen("va.in", "r", stdin);
	freopen("va.out", "w", stdout);
	int n, cnt;
	scanf("%d%d%d", &n, &type, &cnt);
	if (type == 4) scanf("%d", &seed);
	for (int i = 0; i < n; ++i) ans[i] = i + 1;
	solve(0, n - 1);
	for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
	return 0;
}