#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cctype>

using std::min;
using std::queue;

const int M = 10, INF = 1E9;
struct Edge {
    int v, val, next;
} edge[((1 << M) + (1 << M) * M + M) << 1];
int head[(1 << M) + M + 2], dis[(1 << M) + M + 2], ht[1 << M], nn, m, cnt;

inline char GetChar() {
    static const int SIZE = 1 << 20;
    static char buf[SIZE], *s, *t;
    return s == t && (t = (s = buf) + fread(buf, 1, SIZE, stdin), s == t)
               ? EOF
               : *s++;
}

#define getchar GetChar

template<typename T>
inline int GetNum(T &num) {
    char c;
    num=0;
    bool p = false;
    for (c = getchar(); !isdigit(c); c = getchar()) {
        p |= c == '-';
        if (c==EOF) return EOF;
    }
    for (; isdigit(c); c = getchar()) num = (num << 1) + (num << 3) + (c ^ 48);
    num=p?-num:num;
    return 0;
}


void init() {
    memset(head, -1, sizeof head);
    memset(ht, 0, sizeof ht);
    cnt = 0;
    nn = 1 << m;
}

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
    return ~dis[nn + m + 1];
}

int dfs(int k, int val) {
    if (k == nn + m + 1 || !val) return val;
    int ret = 0;
    for (int i = head[k]; ~i; i = edge[i].next) {
        int v = edge[i].v;
        if (edge[i].val && dis[v] == dis[k] + 1) {
            int tmp = dfs(v, min(val, edge[i].val));
            ret += tmp;
            val -= tmp;
            edge[i].val -= tmp;
            edge[i ^ 1].val += tmp;
            if (!val) break;
        }
    }
    if (!ret) dis[k] = -1;
    return ret;
}

int dinic() {
    int ret = 0;
    while (bfs()) ret += dfs(0, INF);
    return ret;
}

int main() {
    int n;
    while (GetNum(n)!=EOF&&GetNum(m)!=EOF) {
        init();
        for (int i = 0; i < n; ++i) {
            int num = 0;
            for (int j = 0; j < m; ++j) {
                int flag;
                GetNum(flag);
                num = num | (flag << j);
            }
            ++ht[num];
        }
        for (int i = 0; i < nn; ++i)
            if (ht[i]) {
                AddNetworkEdge(0, i + 1, ht[i]);
                for (int j = 0; j < m; ++j)
                    if (i & (1 << j)) AddNetworkEdge(i + 1, nn + j + 1, INF);
            }
        for (int i = 1; i <= m; ++i) {
            int val;
            GetNum(val);
            AddNetworkEdge(nn + i, nn + m + 1, val);
        }
        puts(dinic() == n ? "YES" : "NO");
    }
    return 0;
}