// AC
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using std::min;
using std::queue;

const int M = 1000, N = 100, INF = 1E9;
struct Edge {
    int v, val, next;
} edge[N * (M + 1)];
int a[M], head[N + 2], last[M + 1], dis[N + 2], n, cnt;

inline void AddEdge(int u, int v, int val) {
    edge[cnt].v = v;
    edge[cnt].val = val;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

inline void AddNetworkEdge(int u, int v, int val) {
    AddEdge(u, v, val);
    AddEdge(v, u, 0);
}

int bfs() {
    queue<int> q;
    memset(dis, -1, sizeof dis);
    dis[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        for (int i = head[k]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            if (edge[i].val && dis[v] == -1) {
                dis[v] = dis[k] + 1;
                q.push(v);
            }
        }
    }
    return ~dis[n + 1];
}

int dfs(int k, int val) {
    if (k == n + 1 || !val) return val;
    int ret = 0;
    for (int i = head[k]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (dis[v] == dis[k] + 1 && edge[i].val) {
            int tmp = dfs(v, min(edge[i].val, val));
            ret += tmp;
            val -= tmp;
            edge[i].val -= tmp;
            edge[i ^ 1].val += tmp;
            if (!val) break;
        }
    }
    if (ret) dis[k] = -1;
    return ret;
}

int dinic() {
    int ret = 0;
    while (bfs()) ret += dfs(0, INF);
    return ret;
}

int main() {
    int m;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) scanf("%d", a + i);
    memset(head, -1, sizeof head);
    for (int i = 1; i <= n; ++i) {
        int b;
        scanf("%d", &b);
        for (int j = 0; j < b; ++j) {
            int c;
            scanf("%d", &c);
            --c;
            if (!last[c])
                AddNetworkEdge(0, i, a[c]);
            else
                AddNetworkEdge(last[c], i, INF);
            last[c] = i;
        }
        scanf("%d", &b);
        AddNetworkEdge(i, n + 1, b);
    }
    printf("%d", dinic());
    return 0;
}