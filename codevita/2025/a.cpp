#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;           // 原 N <=100
const int MAXV = MAXN * 2 + 2;  // 分裂后顶点数 + SS, TT
const int INF = 0x3f3f3f3f;

struct Edge {
    int to, cap, cost, rev;
};

vector<Edge> g[MAXV];
int h[MAXV], dist[MAXV];       // 潜力, 距离
int prevv[MAXV], preve[MAXV];  // 前驱

void add_edge(int from, int to, int cap, int cost) {
    g[from].push_back({to, cap, cost, (int)g[to].size()});
    g[to].push_back({from, 0, -cost, (int)g[from].size() - 1});
}

int min_cost_flow(int s, int t, int f) {
    int res = 0;
    fill(h, h + MAXV, 0);
    while (f > 0) {
        // Dijkstra 找最短增广路径
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        fill(dist, dist + MAXV, INF);
        dist[s] = 0;
        pq.push({0, s});
        while (!pq.empty()) {
            auto [cost, v] = pq.top();
            pq.pop();
            if (dist[v] < cost) continue;
            for (int i = 0; i < g[v].size(); ++i) {
                Edge &e = g[v][i];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    pq.push({dist[e.to], e.to});
                }
            }
        }
        if (dist[t] == INF) return -1;  // 无增广路径
        // 更新潜力
        for (int v = 0; v < MAXV; ++v)
            if (dist[v] < INF) h[v] += dist[v];
        // 沿前驱增广
        int d = f;
        for (int v = t; v != s; v = prevv[v]) {
            d = min(d, g[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * h[t];  // h[t] 是路径费用
        for (int v = t; v != s; v = prevv[v]) {
            Edge &e = g[prevv[v]][preve[v]];
            e.cap -= d;
            g[v][e.rev].cap += d;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        N = max(N, max(a, b));
        edges[i] = make_pair(a, b);
    }
    vector<vector<int>> adj(N);
    for (auto [a, b] : edges) {
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int s1, s2;
    cin >> s1 >> s2;
    s1--;
    s2--;
    int T;
    cin >> T;
    T--;
    if (s1 == s2 && s1 != T) {
        cout << "Impossible\n";
        return 0;
    }

    // 分裂顶点：0~N-1 原顶点，N~2N-1 为 *_out (in=原, out=原+N)
    int SS = 2 * N, TT = 2 * N + 1;
    // S1, S2, T 不分裂或特殊：假设 S1/S2/T 用原索引作为 out，in 不需（简化）
    // 标准：所有非T分裂，S1/S2/T 调整
    // 为简单：分裂所有，包括S/T，但S/T的in-out cap=INF（允许多用S少用T）
    for (int v = 0; v < N; ++v) {
        int vin = v, vout = v + N;
        int cap_v = (v == T ? INF : 1);       // T 无限容量
        if (v == s1 || v == s2) cap_v = INF;  // S 可多用？ 但起点不同，无需
        add_edge(vin, vout, cap_v, 0);        // v_in -> v_out
    }
    // 原边
    for (int u = 0; u < N; ++u) {
        for (int v : adj[u]) {
            if (v > u) continue;         // 避免双边
            add_edge(u + N, v, INF, 1);  // u_out -> v_in
            add_edge(v + N, u, INF, 1);  // v_out -> u_in
        }
    }
    // 超级源到 S1_out, S2_out
    add_edge(SS, s1 + N, 1, 0);
    add_edge(SS, s2 + N, 1, 0);
    // T_in -> TT
    add_edge(T, TT, 2, 0);  // T_in = T (未分裂用原)

    // T 是 vin=T, 但从路径入 T_in =T, 出无需
    // 调整：路径到 T_in, 无需 T_out
    // 以上 T_in -> TT cap2 cost0

    int cost = min_cost_flow(SS, TT, 2);
    if (cost == -1 || cost == INF) {
        cout << "Impossible\n";
    } else {
        cout << cost << "\n";  // 总费用 = 总边数
    }
    return 0;
}