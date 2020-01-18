//AC
#include <cstdio>
#include <cstring>

const int N = 2000, M = 6000;
struct Edge {
    int v, next;
} edge[M];
int head[N], f[N], cnt;
bool vis[N];

inline void AddEdge(int u, int v) {
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

int sg(int k) {
    // printf("#%d\n", k);
    if (vis[k]) return f[k];
    vis[k] = true;
    bool flag[N];
    memset(flag, 0, sizeof flag);
    for (int i = head[k]; ~i; i = edge[i].next) flag[sg(edge[i].v)] = true;
    for (int i = 0;; ++i)
        if (!flag[i]) {
            f[k] = i;
            break;
        }
    return f[k];
}

int main() {
    int n, m, k, ans = 0;
    scanf("%d%d%d", &n, &m, &k);
    memset(head, -1, sizeof head);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        AddEdge(u - 1, v - 1);
    }
    for (int i = 0; i < k; ++i) {
        int a;
        scanf("%d", &a);
        ans ^= sg(a - 1);
    }
    puts(ans ? "win" : "lose");
    return 0;
}