// AC
#include <algorithm>
#include <cstdio>
#include <cstring>

using std::max;

const int N = 10000, M = N << 1;
struct Edge
{
	int v, dis, next;
} edge[M << 1];
int head[N], s, t, cnt;
bool vis[N];

void AddEdge(int u, int v, int dis)
{
	edge[cnt].v = v;
	edge[cnt].dis = dis;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

void dfs(int k, int lim)
{
	vis[k] = true;
	for (int i = head[k]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		if (!vis[v] && edge[i].dis <= lim) dfs(v, lim);
	}
}

bool check(int lim)
{
	memset(vis, 0, sizeof vis);
	dfs(s, lim);
	return vis[t];
}

int main()
{
	int n, m, l = 0, r = 0;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	--s;
	--t;
	memset(head, -1, sizeof head);
	while (m--)
	{
		int u, v, dis;
		scanf("%d%d%d", &u, &v, &dis);
		--u;
		--v;
		AddEdge(u, v, dis);
		AddEdge(v, u, dis);
		r = max(r, dis);
	}
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	printf("%d", l);
	return 0;
}