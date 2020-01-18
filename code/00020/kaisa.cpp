// AC
#include <algorithm>
#include <cstdio>
#include <cstring>

using std::max;
using std::memset;
using std::printf;
using std::scanf;

const int N = 50000;
struct Edge {
    int v, next;
} edge[(N - 1) << 1];
int head[N], f[N][2], cnt;

void AddEdge(int u, int v) {
    edge[cnt] = {v, head[u]};
    head[u] = cnt++;
}

void dfs(int k) {
    f[k][1] = 1;
    for (int i = head[k]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (!f[v][1]) {
            dfs(v);
            f[k][1] += f[v][0];
            f[k][0] += max(f[v][0], f[v][1]);
        }
    }
}

int main() {
    freopen("kaisa.in", "r", stdin);
    freopen("kaisa.out", "w", stdout);
    int n;
    scanf("%d", &n);
    memset(head, -1, sizeof head);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        AddEdge(u, v);
        AddEdge(v, u);
    }
    dfs(0);
    printf("%d", max(f[0][1], f[0][0]));
    return 0;
}
