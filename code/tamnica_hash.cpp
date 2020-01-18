#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N1 = 2000000, M = 500000, N2 = M << 1, key = 1000007;
struct Edge {
    int v, next;
    long long len;
} e[M + N2];
long long h[N1], s[N2], head[N1], d[N1];
int q[N2], tot;

int hash(long long u) {
    int i = u % key;
    for (; h[i] && h[i] != u; i++)
        ;
    return i;
}

void add_edge(int u, int v, long long len) {
    e[++tot].next = head[u];
    e[tot].v = v;
    e[tot].len = len;
    head[u] = tot;
}

int main() {
    freopen("tamnica.in", "r", stdin);
    freopen("tamnica.out", "w", stdout);
    int m, t, k2, a, b, l, r;
    long long n, x, y;
    scanf("%lld%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld", &x, &y);
        if (y < x) swap(x, y);
        int k1 = hash(x), k2 = hash(y);
        add_edge(k1, k2, 1);
        h[k1] = x;
        h[k2] = y;
        s[i << 1] = x;
        s[(i << 1) + 1] = y;
    }
    h[k2 = a = hash(1)] = 1;
    h[b = hash(n)] = n;
    s[m << 1] = 1;
    s[(m << 1) + 1] = n;
    t = (m + 1) << 1;
    sort(s, s + t);
    t = unique(s, s + t) - s;
    for (int i = 1; i < t; i++) {
        int k1 = k2;
        k2 = hash(s[i]);
        int len = s[i] - s[i - 1];
        add_edge(k1, k2, len);
        add_edge(k2, k1, len);
    }
    memset(d, 127, sizeof d);
    d[a] = 0;
    l = 0;
    r = 1;
    q[0] = a;
    vis[a] = true;
    while (vis[q[l]]) {
        vis[q[l]] = false;
        for (int i = head[q[l]]; i; i = e[i].next)
            if (d[q[l]] + e[i].len < d[e[i].v]) {
                d[e[i].v] = d[q[l]] + e[i].len;
                if (!vis[e[i].v]) {
                    vis[e[i].v] = true;
                    q[r] = e[i].v;
                    r = (r + 1) % N2;
                }
            }
        l = (l + 1) % N2;
    }
    printf("%lld", d[b]);
    return 0;
}
