//题目错，没有多项式复杂度解法 70分解法，答案正确
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

using std::pair;
using std::queue;

const int N = 100, K = 10;
struct Edge
{
	int v, dis, next;
} edge[N * N << 1];
int c[N], a[K], b[1 << K], head[N], dis[N][1 << K], k, cnt;
bool vis[N][1 << K];

void AddEdge(int u, int v, int dis)
{
	edge[cnt].v = v;
	edge[cnt].dis = dis;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

int spfa(int s, int t)
{
	int ret = 1000000000;
	memset(dis, 127, sizeof dis);
	dis[s][1 << c[s]] = 0;
	vis[s][1 << c[s]] = true;
	queue<pair<int, int> > q;
	q.push(pair<int, int>(s, 1 << c[s]));
	while (!q.empty())
	{
		int k = q.front().first, ss = q.front().second;
		q.pop();
		for (int i = head[k]; ~i; i = edge[i].next)
		{
			int v = edge[i].v, c1 = 1 << c[v];
			if (ss & c1 || ss & a[c[v]]) continue;
			int tmp = ss | c1;
			// printf("#%d %d\n", v, tmp);
			if (dis[k][ss] + edge[i].dis < dis[v][tmp])
			{
				dis[v][tmp] = dis[k][ss] + edge[i].dis;
				if (!vis[v][tmp])
				{
					vis[v][tmp] = true;
					q.push(pair<int, int>(v, tmp));
				}
			}
		}
		vis[k][ss] = false;
	}
	for (int i = 0; i < 1 << k; ++i)
		if (dis[t][i] < ret) ret = dis[t][i];
	return ret == 1000000000 ? -1 : ret;
}

int main()
{
	int n, m, s, t;
	scanf("%d%d%d%d%d", &n, &k, &m, &s, &t);
	--s;
	--t;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", c + i);
		--c[i];
	}
	for (int i = 0; i < k; ++i)
		for (int j = 0; j < k; ++j)
		{
			int tmp;
			scanf("%d", &tmp);
			a[i] |= tmp << j;
		}
	memset(head, -1, sizeof head);
	while (m--)
	{
		int u, v, dis;
		scanf("%d%d%d", &u, &v, &dis);
		--u;
		--v;
		AddEdge(u, v, dis);
		AddEdge(v, u, dis);
	}
	printf("%d", spfa(s, t));
	return 0;
}