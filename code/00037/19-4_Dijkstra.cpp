// AC
#include <cstdio>
#include <cstring>

using std::memset;
using std::scanf;

const int N = 1000;
const long long P = ((long long)1 << 31) - 1;
int edge[N][N], dist[N], cnt[N];
bool vis[N];

int main() {
    int n, m;
    long long ans = 1;
    scanf("%d%d", &n, &m);
    memset(edge, 63, sizeof edge);
    for (int i = 0; i < m; ++i) {
        int u, v, len;
        scanf("%d%d%d", &u, &v, &len);
        --u;
        --v;
        edge[u][v] = edge[v][u] = len;
    }
    memset(dist, 127, sizeof dist);
    dist[0] = 0;
    for (int i = 0; i < n; ++i) {
        int k = -1;
        for (int j = 0; j < n; ++j)
            if (!vis[j] && (k == -1 || dist[j] < dist[k])) k = j;
        for (int j = 0; j < n; ++j)
            cnt[k] += vis[j] && dist[j] + edge[j][k] == dist[k];
        vis[k] = true;
        for (int j = 0; j < n; ++j)
            if (!vis[j] && dist[k] + edge[k][j] < dist[j])
                dist[j] = dist[k] + edge[k][j];
    }
    for (int i = 1; i < n; ++i) ans = (ans * cnt[i]) % P;
    printf("%lld", ans);
    return 0;
}