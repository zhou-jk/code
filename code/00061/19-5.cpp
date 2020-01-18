// AC
#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;

const int N = 100000;
struct Edge {
    int v, next;
} edge[N - 1];
int c[N], t[N], head[N], f[N], cnt;
long long ans;

inline void AddEdge(int u, int v) {
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

long long dfs(int k) {
    long long ret = 0;
    f[k] = t[k];
    for (int i = head[k]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        ret += dfs(v);
        f[k] = min(f[k], f[v]);
    }
    if (ret < c[k]) {
        ans += (c[k] - ret) * f[k];
        ret = c[k];
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    memset(head, -1, sizeof head);
    for (int i = 0; i < n; ++i) {
        int fa;
        scanf("%d%d%d", &fa, c + i, t + i);
        if (~fa) AddEdge(fa - 1, i);
    }
    dfs(0);
    printf("%lld", ans);
    return 0;
}
