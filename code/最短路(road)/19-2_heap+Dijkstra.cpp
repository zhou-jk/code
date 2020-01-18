// AC
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using std::max;
using std::min;

const int N = 1000000, M = 10000000;
struct Edge
{
	int v, dis, next;
} edge[M];
struct Node
{
	int k;
	long long dis;
	bool operator<(const Node &b) const { return dis > b.dis; }
};
int head[N], cnt;
long long dis[N];
bool vis[N];

void AddEdge(int u, int v, int dis)
{
	// printf("%d %d %d\n", u, v, dis);
	edge[cnt].v = v;
	edge[cnt].dis = dis;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

int main()
{
	std::priority_queue<Node> h;
	int n, m, k, rxa, rxc, rya, ryc, rp, x = 0, y = 0;
	scanf("%d%d%d%d%d%d%d%d", &n, &m, &k, &rxa, &rxc, &rya, &ryc, &rp);
	memset(head, -1, sizeof head);
	while (k-- && m--)
	{
		// puts("$");
		x = (x * rxa + rxc) % rp;
		y = (y * rya + ryc) % rp;
		int a = min(x % n, y % n), b = max(y % n, y % n);
		AddEdge(a, b, 100000000 - (a + 1) * 100);
	}
	while (m--)
	{
		int u, v, dis;
		scanf("%d%d%d", &u, &v, &dis);
		--u;
		--v;
		AddEdge(u, v, dis);
	}
	memset(dis, 127, sizeof dis);
	dis[0] = 0;
	h.push(Node{0, 0});
	while (!h.empty())
	{
		int k = h.top().k, tmp = h.top().dis;
		h.pop();
		if (vis[k]) continue;
		vis[k] = true;
		for (int i = head[k]; ~i; i = edge[i].next)
		{
			int v = edge[i].v;
			// printf("#%d %d\n", k, v);
			if (tmp + edge[i].dis < dis[v])
			{
				dis[v] = tmp + edge[i].dis;
				h.push(Node{v, dis[v]});
			}
		}
	}
	printf("%d", dis[n - 1]);
	return 0;
}