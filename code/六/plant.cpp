#include <cstdio>
#include <queue>
#include <utility>

using std::pair;
using std::printf;
using std::priority_queue;
using std::scanf;

const int N = 200000;
int a[N], l[N], r[N];
bool vis[N];
priority_queue<pair<int, int> > h;

int main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	if (m << 1 > n)
	{
		puts("Error!");
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
		l[i] = (i - 1 + n) % n;
		r[i] = (i + 1) % n;
		h.push(pair<int, int>(a[i], i));
	}
	while (m--)
	{
		while (vis[h.top().second]) h.pop();
		pair<int, int> tmp = h.top();
		h.pop();
		int id = tmp.second;
		vis[l[id]] = vis[r[id]] = true;
		ans += a[id];
		a[id] = a[l[id]] + (l[id] != r[id]) * a[r[id]] - a[id];
		l[id] = l[l[id]];
		r[id] = r[r[id]];
		l[r[id]] = id;
		r[l[id]] = id;
		h.push(pair<int, int>(a[id], id));
	}
	printf("%d", ans);
	return 0;
}