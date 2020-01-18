// AC
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using std::min;
using std::sort;

const int N = 2000;
const double EPS = 0.001;
int x[N], y[N], s[N][N], dis[N], ans[N];
bool vis[N];

int calc(int x1, int y1, int x2, int y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
	freopen("apex.in", "r", stdin);
	freopen("apex.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d%d", x + i, y + i);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) s[i][j] = calc(x[i], y[i], x[j], y[j]);
	memset(dis, 127, sizeof dis);
	dis[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		int k = -1;
		for (int j = 0; j < n; ++j)
			if (!vis[j] && (k == -1 || dis[j] < dis[k])) k = j;
		vis[k] = true;
		ans[i] = dis[k];
		for (int j = 0; j < n; ++j) dis[j] = min(dis[j], s[k][j]);
	}
	sort(ans, ans + n);
	printf("%.2f", sqrt(ans[n - m]));
	return 0;
}
