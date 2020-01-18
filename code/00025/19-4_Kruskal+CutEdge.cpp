// AC
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 3000;
struct Edge {
    int v, next;
} edge2[N * (N - 1)];
int head[N], low[N], dfn[N], fa[N], n_edge, cnt, ans;
vector<pair<int, int> > edge1[N];

void add_edge(int u, int v) {
    edge2[n_edge] = Edge{v, head[u]};
    head[u] = n_edge++;
}

void dfs(int k, int fa) {
    low[k] = dfn[k] = ++cnt;
    for (int i = head[k]; i > -1; i = edge2[i].next)
        if (fa != (i ^ 1)) {
            if (!dfn[edge2[i].v]) {
                dfs(edge2[i].v, i);
                low[k] = min(low[k], low[edge2[i].v]);
                if (dfn[k] < low[edge2[i].v])
                    ans++;  //,printf("%d %d\n",k,edge2[i].v);
            } else
                low[k] = min(low[k], dfn[edge2[i].v]);
        }
}

int get_fa(int k) { return k == fa[k] ? k : fa[k] = get_fa(fa[k]); }

int main() {
    int t, n, w;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        ans = 0;
        for (int j = 0; j < N; j++) edge1[j].clear();
        for (int j = 0; j < n; j++) {
            fa[j] = j;
            for (int k = j + 1; k < n; k++) {
                scanf("%d", &w);
                edge1[w - 1].push_back(make_pair(j, k));
            }
        }
        for (int j = 0; j < N; j++) {
            memset(head, -1, sizeof head);
            n_edge = 0;
            memset(dfn, 0, sizeof dfn);
            cnt = 0;
            for (int k = 0; k < edge1[j].size(); k++) {
                int x = get_fa(edge1[j][k].first),
                    y = get_fa(edge1[j][k].second);
                if (x != y)
                    add_edge(x, y),
                        add_edge(y, x);  //连祖先，避免以前的边被加进环
            }
            for (int k = 0; k < edge1[j].size(); k++) {
                int x = get_fa(edge1[j][k].first),
                    y = get_fa(edge1[j][k].second);
                if (x != y) fa[x] = y;  //必须和前面的循环的分开,否则会漏加入边
            }
            for (int k = 0; k < n; k++)
                if (!dfn[k]) dfs(k, -1);
        }
        printf("%d\n", ans);
    }
    return 0;
}