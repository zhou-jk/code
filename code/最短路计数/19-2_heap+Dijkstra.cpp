// AC
#include <cstdio>
#include <cstring>
#include <queue>

const int N = 1000000, M = 2000000, D = 100003, S = 0;
struct Edge
{
	int v, next;
} edge[M];
struct Node
{
	int k, dis;
	bool operator<(const Node &b) const { return dis > b.dis; }
};
int head[N], dis[N], f[N], cnt;
bool vis[N];

void AddEdge(int u, int v)
{
	edge[cnt].v = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

int main()
{
	std::priority_queue<Node> h;
	int n, m;
	scanf("%d%d", &n, &m);
	memset(head, -1, sizeof head);
	while (m--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		AddEdge(u, v);
		AddEdge(v, u);
	}
	memset(dis, 127, sizeof dis);
	dis[S] = 0;
	f[S] = 1 % D;
	h.push(Node{S, 0});
	while (!h.empty())
	{
		int k = h.top().k, tmp = h.top().dis;
		h.pop();
		if (vis[k]) continue;
		vis[k] = true;
		for (int i = head[k]; ~i; i = edge[i].next)
			if (tmp + 1 < dis[edge[i].v])
			{
				f[edge[i].v] = f[k];
				dis[edge[i].v] = tmp + 1;
				h.push(Node{edge[i].v, dis[edge[i].v]});
			}
			else if (tmp + 1 == dis[edge[i].v])
				f[edge[i].v] = (f[edge[i].v] + f[k]) % D;
	}
	for (int i = 0; i < n; ++i) printf("%d\n", f[i]);
	return 0;
}