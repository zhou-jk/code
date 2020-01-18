// AC
#include <algorithm>
#include <cstdio>

using std::max;
using std::sort;
using std::swap;

const int N = 100, M = 1000, P = 31011;
struct Edge {
    int u, v, len;
    bool operator<(const Edge &b) const { return len < b.len; }
} edge[M];
struct EdgeSet {
    int l, r, need;
    EdgeSet() : need(0) {}
} s[M];
int fa[N], dep[N], n, tot;

void init() {
    for (int i = 0; i < n; ++i) {
        fa[i] = i;
        dep[i] = 1;
    }
}

int GetFa(int k) { return k == fa[k] ? k : GetFa(fa[k]); }

void Merge(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    fa[y] = x;
    dep[x] = max(dep[x], dep[y] + 1);
}

void dfs(int k1, int k2, int cnt) {
    if (k2 == s[k1].r + 1) {
        tot += cnt == s[k1].need;
        return;
    }
    dfs(k1, k2 + 1, cnt);
    int x = GetFa(edge[k2].u), y = GetFa(edge[k2].v);
    if (x != y) {
        Merge(x, y);
        dfs(k1, k2 + 1, cnt + 1);
        fa[x] = x;
        fa[y] = y;
    }
}

int main() {
    int m, cnt = 1, ans = 1;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].len);
        --edge[i].u;
        --edge[i].v;
    }
    sort(edge, edge + m);
    init();
    s[0].l = 0;
    for (int i = 0; i < m; ++i) {
        if (i && edge[i].len != edge[i - 1].len) {
            s[cnt - 1].r = i - 1;
            s[cnt++].l = i;
        }
        int x = GetFa(edge[i].u), y = GetFa(edge[i].v);
        if (x != y) {
            Merge(x, y);
            ++s[cnt - 1].need;
            ++tot;
        }
    }
    s[cnt - 1].r = m - 1;
    if (tot != n - 1) {
        putchar('0');
        return 0;
    }
    init();
    for (int i = 0; i < cnt; ++i) {
        tot = 0;
        dfs(i, s[i].l, 0);
        tot %= P;
        ans = ans * tot % P;
        for (int j = s[i].l; j <= s[i].r; ++j) {
            int x = GetFa(edge[j].u), y = GetFa(edge[j].v);
            if (x != y) Merge(x, y);
        }
    }
    printf("%d", ans);
    return 0;
}