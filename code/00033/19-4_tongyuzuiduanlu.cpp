// AC
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using std::priority_queue;
using std::swap;

struct Node {
    int k;
    unsigned long long dist;
    bool operator<(const Node &b) const { return dist > b.dist; }
};

struct Edge {
    int v, len, next;
};

const int N = 100000;
Edge edge[N << 1];
int head[N], cnt;
bool vis[N];
unsigned long long dist[N];
priority_queue<Node> heap;

void AddEdge(int u, int v, int len) {
    edge[cnt] = {v, len, head[u]};
    head[u] = cnt++;
}

int main() {
    unsigned long long h, ans = 0;
    int a, b, c;
    scanf("%llu%d%d%d", &h, &a, &b, &c);
    if (c < a) swap(a, c);
    if (c < b) swap(b, c);
    if (!c) {
        puts("1");
        return 0;
    }
    --h;
    memset(head, -1, sizeof head);
    for (int i = 0; i < c; ++i) {
        AddEdge(i, (i + a) % c, a);
        AddEdge(i, (i + b) % c, b);
    }
    for (int i = 1; i < c; ++i) dist[i] = (unsigned long long)1 << 63;
    heap.push(Node{0, 0});
    while (!heap.empty()) {
        Node now = heap.top();
        heap.pop();
        if (vis[now.k]) continue;
        vis[now.k] = true;
        for (int i = head[now.k]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            if (now.dist + edge[i].len < dist[v]) {
                dist[v] = now.dist + edge[i].len;
                heap.push(Node{v, dist[v]});
            }
        }
    }
    for (int i = 0; i < c; ++i)
        if (dist[i] <= h) ans += (h - dist[i]) / c + 1;
    printf("%lld", ans);
    return 0;
}
