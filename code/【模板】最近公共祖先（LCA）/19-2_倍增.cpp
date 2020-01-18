#include <algorithm>
#include <cstdio>
#include <cstring>

using std::memset;
using std::scanf;
using std::swap;

const int N = 500000;
struct Edge
{
	int v, next;
} edge[(N - 1) << 1];
int fa[N][19], head[N], dep[N], lg[N + 1], n, cnt;

void AddEdge(int u, int v)
{
	edge[cnt].v = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

void dfs(const int k)
{
	for (int i = head[k]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == fa[k][0]) continue;
		// printf("#%d %d\n", k, v);
		dep[v] = dep[k] + 1;
		fa[v][0] = k;
		dfs(v);
	}
}

void init()
{
	for (int i = 1; (1 << i) <= n; ++i)
		for (int j = 0; j < n; ++j) fa[j][i] = fa[fa[j][i - 1]][i - 1];
	for (int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
}

int lca(int x, int y)
{
	// printf("%d %d\n", x, y);
	if (dep[x] < dep[y]) swap(x, y);
	while (dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]]];
	// printf("%d %d %d %d\n", x, y, dep[x], dep[y]);
	if (x == y) return x;
	for (int i = lg[dep[x]]; ~i; --i)
		if (fa[x][i] != fa[y][i])
		{
			x = fa[x][i];
			y = fa[y][i];
		}
	// printf("%d %d %d %d\n", x, y, fa[x][0], fa[y][0]);
	return fa[x][0];
}

int main()
{
	int q, rt;
	scanf("%d%d%d", &n, &q, &rt);
	memset(head, -1, sizeof head);
	for (int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		AddEdge(u, v);
		AddEdge(v, u);
	}
	fa[rt - 1][0] = rt - 1;
	dfs(rt - 1);
	init();
	while (q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", lca(x - 1, y - 1) + 1);
	}
	return 0;
}