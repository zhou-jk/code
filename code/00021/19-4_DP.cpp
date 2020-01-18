// AC
#include <algorithm>
#include <cstdio>
#include <cstring>

using std::max;
using std::memset;
using std::printf;
using std::scanf;

const int N = 6000;
struct Edge {
    int v, next;
} edge[N - 1];
int a[N], head[N], ind[N], f[N][2], cnt;

void AddEdge(int u, int v) {
    edge[cnt] = {v, head[u]};
    head[u] = cnt++;
}

void dfs(int k) {
    f[k][1] = a[k];
    for (int i = head[k]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        dfs(v);
        f[k][1] += f[v][0];
        f[k][0] += max(f[v][0], f[v][1]);
    }
}

int main() {
    int n, s;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    memset(head, -1, sizeof head);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &v, &u);
        --u;
        --v;
        AddEdge(u, v);
        ++ind[v];
    }
    for (int i = 0; i < n; ++i)
        if (!ind[i]) s = i;
    dfs(s);
    printf("%d", max(f[s][1], f[s][0]));
    return 0;
}