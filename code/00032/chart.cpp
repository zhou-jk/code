// AC
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <vector>

using std::min;
using std::vector;

struct Edge {
    int v, next;
};

const int N = 100000, M = 500000;
Edge edge[M << 1];
int head[N], size[N], dfn[N], low[N], n, cnt1, cnt2;
long long ans[N];

inline char GetChar() {
    static const int SIZE = 1 << 20;
    static char buf[SIZE], *s, *t;
    return s == t && (t = (s = buf) + fread(buf, 1, SIZE, stdin), s == t)
               ? EOF
               : *s++;
}

#define getchar GetChar

inline int GetInt() {
    char c;
    int ret = 0;
    bool p = false;
    for (c = getchar(); !isdigit(c); c = getchar()) p |= c == '-';
    for (; isdigit(c); c = getchar()) ret = (ret << 1) + (ret << 3) + (c ^ 48);
    return p ? -ret : ret;
}

void PutInt(long long num) {
    if (num > 9) PutInt(num / 10);
    putchar((num % 10) ^ 48);
}

inline void AddEdge(int u, int v) {
    edge[cnt1] = {v, head[u]};
    head[u] = cnt1++;
}

void dfs(int k) {
    int sum = 0;
    dfn[k] = low[k] = ++cnt2;
    size[k] = 1;
    for (int i = head[k]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (!dfn[v]) {
            dfs(v);
            size[k] += size[v];
            low[k] = min(low[k], low[v]);
            if (low[v] >= dfn[k]) {
                ans[k] += (long long)size[v] * sum;
                sum += size[v];
            }
        } else
            low[k] = min(low[k], dfn[v]);
    }
    ans[k] += n - 1 + (long long)(n - sum - 1) * sum;
    ans[k] <<= 1;
}

int main() {
    freopen("chart.in", "r", stdin);
    freopen("chart.out", "w", stdout);
    n = GetInt();
    int m = GetInt();
    memset(head, -1, sizeof head);
    for (int i = 0; i < m; ++i) {
        int u = GetInt() - 1, v = GetInt() - 1;
        AddEdge(u, v);
        AddEdge(v, u);
    }
    dfs(0);
    for (int i = 0; i < n; ++i) {
        PutInt(ans[i]);
        putchar('\n');
    }
    return 0;
}
