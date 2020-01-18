#define N 2000
#define M 20000

#include <cstdio>
#include <algorithm>

using namespace std;

struct Edge
{
	int x, y, l;
} e[M];
int fa[N], ans;

bool cmp(Edge &a, Edge &b)
{
	return a.l < b.l;
}

int get_fa(int k)
{
	return fa[k] == k ? k : fa[k] = get_fa(fa[k]);
}

int main()
{
	freopen("anet.in", "r", stdin);
	freopen("anet.out", "w", stdout);
	int m, n, cnt;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].l);
		e[i].x--;
		e[i].y--;
	}
	sort(e, e + m, cmp);
	for (int i = 0; i < n; i++)
		fa[i] = i;
	cnt = n - 1;
	for (int i = 0; i < m && cnt; i++)
	{
		int x = get_fa(e[i].x), y = get_fa(e[i].y);
		if (x != y)
		{
			fa[x] = y;
			ans = e[i].l;
			cnt--;
		}
	}
	printf("%d", ans);
	return 0;
}
