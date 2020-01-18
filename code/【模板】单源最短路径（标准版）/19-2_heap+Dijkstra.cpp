// AC
#include <cstdio>
#include <cstring>
#include <queue>

const int N = 100000, M = 200000;
struct Edge
{
	int v, dis, next;
} edge[M];
struct Node
{
	int k, dis;
	bool operator<(const Node &b) const { return dis > b.dis; }
};
int head[N], dis[N], cnt;
bool vis[N];

void AddEdge(int u, int v, int dis)
{
	edge[cnt].v = v;
	edge[cnt].dis = dis;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

int main()
{
	std::priority_queue<Node> h;
	int n, m, s;
	scanf("%d%d%d", &n, &m, &s);
	--s;
	memset(head, -1, sizeof head);
	while (m--)
	{
		int u, v, dis;
		scanf("%d%d%d", &u, &v, &dis);
		--u;
		--v;
		AddEdge(u, v, dis);
	}
	memset(dis, 127, sizeof dis);
	dis[s] = 0;
	h.push(Node{s, 0});
	while (!h.empty())
	{
		int k = h.top().k, tmp = h.top().dis;
		h.pop();
		if (vis[k]) continue;
		vis[k] = true;
		for (int i = head[k]; ~i; i = edge[i].next)
			if (tmp + edge[i].dis < dis[edge[i].v])
			{
				dis[edge[i].v] = tmp + edge[i].dis;
				h.push(Node{edge[i].v, dis[edge[i].v]});
			}
	}
	for (int i = 0; i < n; ++i) printf("%d ", dis[i]);
	return 0;
}