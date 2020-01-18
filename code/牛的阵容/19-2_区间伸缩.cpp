// AC
#include <algorithm>
#include <cstdio>
#include <map>
#include <utility>

using std::map;
using std::min;
using std::pair;
using std::sort;

const int N = 50000;
pair<int, int> a[N];
map<int, int> h;
int vis[N];

int main()
{
	int n, k = -1, s = 0, cnt = 0, ans = 2E9;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
		if (!h.count(a[i].second)) h[a[i].second] = cnt++;
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
	{
		while (s < cnt)
		{
			++k;
			if (k == n) break;
			int &v = vis[h[a[k].second]];
			s += !v;
			++v;
		}
		if (s == cnt)
			ans = min(ans, a[k].first - a[i].first);
		else if (k == n)
			break;
		int &v = vis[h[a[i].second]];
		--v;
		s -= !v;
	}
	printf("%d", ans);
	return 0;
}