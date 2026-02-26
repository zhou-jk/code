#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph {
   public:
    struct edge {
        int from;
        int to;
        T cost;
    };

    vector<edge> edges;
    vector<vector<int>> g;
    int n;

    graph(int _n) : n(_n) { g.resize(n); }

    virtual int add(int from, int to, T cost) = 0;
};

template <typename T>
class undirectedgraph : public graph<T> {
   public:
    using graph<T>::edges;
    using graph<T>::g;
    using graph<T>::n;

    undirectedgraph(int _n) : graph<T>(_n) {}

    int add(int from, int to, T cost = 1) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        int id = (int)edges.size();
        g[from].push_back(id);
        g[to].push_back(id);
        edges.push_back({from, to, cost});
        return id;
    }
};

template <typename T>
vector<int> find_max_unweighted_matching(const undirectedgraph<T> &g) {
    std::mt19937 rng(114514);
    vector<int> match(g.n, -1);
    vector<int> aux(g.n, -1);
    vector<int> label(g.n);
    vector<int> orig(g.n);
    vector<int> parent(g.n, -1);
    queue<int> q;
    int aux_time = -1;

    auto lca = [&](int v, int u) {
        aux_time++;
        while (true) {
            if (v != -1) {
                if (aux[v] == aux_time) {
                    return v;
                }
                aux[v] = aux_time;
                if (match[v] == -1) {
                    v = -1;
                } else {
                    v = orig[parent[match[v]]];
                }
            }
            swap(v, u);
        }
    };

    auto blossom = [&](int v, int u, int a) {
        while (orig[v] != a) {
            parent[v] = u;
            u = match[v];
            if (label[u] == 1) {
                label[u] = 0;
                q.push(u);
            }
            orig[v] = orig[u] = a;
            v = parent[u];
        }
    };

    auto augment = [&](int v) {
        while (v != -1) {
            int pv = parent[v];
            int next_v = match[pv];
            match[v] = pv;
            match[pv] = v;
            v = next_v;
        }
    };

    auto bfs = [&](int root) {
        fill(label.begin(), label.end(), -1);
        iota(orig.begin(), orig.end(), 0);
        while (!q.empty()) {
            q.pop();
        }
        q.push(root);
        label[root] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : g.g[v]) {
                auto &e = g.edges[id];
                int u = e.from ^ e.to ^ v;
                if (label[u] == -1) {
                    label[u] = 1;
                    parent[u] = v;
                    if (match[u] == -1) {
                        augment(u);
                        return true;
                    }
                    label[match[u]] = 0;
                    q.push(match[u]);
                    continue;
                } else if (label[u] == 0 && orig[v] != orig[u]) {
                    int a = lca(orig[v], orig[u]);
                    blossom(u, v, a);
                    blossom(v, u, a);
                }
            }
        }
        return false;
    };

    auto greedy = [&]() {
        vector<int> order(g.n);
        iota(order.begin(), order.end(), 0);
        shuffle(order.begin(), order.end(), rng);

        for (int i : order) {
            if (match[i] == -1) {
                for (auto id : g.g[i]) {
                    auto &e = g.edges[id];
                    int to = e.from ^ e.to ^ i;
                    if (match[to] == -1) {
                        match[i] = to;
                        match[to] = i;
                        break;
                    }
                }
            }
        }
    };

    greedy();
    for (int i = 0; i < g.n; i++) {
        if (match[i] == -1) {
            bfs(i);
        }
    }
    return match;
}
constexpr int MAXL = 105;
bool wallv[MAXL][MAXL];
bool wallh[MAXL][MAXL];
int rmap[MAXL][MAXL];
struct RegionInfo {
    int min_x = 1000, max_x = -1;
    int min_y = 1000, max_y = -1;
    int count = 0;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int N;
    cin >> N;
    memset(wallv, 0, sizeof(wallv));
    memset(wallh, 0, sizeof(wallh));
    memset(rmap, -1, sizeof(rmap));
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            for (int y = min(y1, y2); y < max(y1, y2); y++) {
                if (x1 > 0 && x1 <= n) wallv[x1][y] = true;
            }
        } else {
            for (int x = min(x1, x2); x < max(x1, x2); x++) {
                if (y1 > 0 && y1 <= m) wallh[x][y1] = true;
            }
        }
    }
    vector<RegionInfo> regions;
    int rcnt = 0;
    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (rmap[x][y] == -1) {
                RegionInfo info;
                queue<pair<int, int>> q;
                q.emplace(x, y);
                rmap[x][y] = rcnt;
                while (!q.empty()) {
                    auto [cx, cy] = q.front();
                    q.pop();
                    info.count++;
                    info.min_x = min(info.min_x, cx);
                    info.max_x = max(info.max_x, cx);
                    info.min_y = min(info.min_y, cy);
                    info.max_y = max(info.max_y, cy);
                    if (cx > 0 && !wallv[cx][cy] && rmap[cx - 1][cy] == -1) {
                        rmap[cx - 1][cy] = rcnt;
                        q.emplace(cx - 1, cy);
                    }
                    if (cx < n - 1 && !wallv[cx + 1][cy] && rmap[cx + 1][cy] == -1) {
                        rmap[cx + 1][cy] = rcnt;
                        q.emplace(cx + 1, cy);
                    }
                    if (cy > 0 && !wallh[cx][cy] && rmap[cx][cy - 1] == -1) {
                        rmap[cx][cy - 1] = rcnt;
                        q.emplace(cx, cy - 1);
                    }
                    if (cy < m - 1 && !wallh[cx][cy + 1] && rmap[cx][cy + 1] == -1) {
                        rmap[cx][cy + 1] = rcnt;
                        q.emplace(cx, cy + 1);
                    }
                }
                regions.push_back(info);
                rcnt++;
            }
        }
    }
    for (const auto &r : regions) {
        int w = r.max_x - r.min_x + 1;
        int h = r.max_y - r.min_y + 1;
        if (r.count != w * h) {
            cout << "Invalid";
            return 0;
        }
    }
    for (int x = 1; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (wallv[x][y] && rmap[x - 1][y] == rmap[x][y]) {
                cout << "Invalid";
                return 0;
            }
        }
    }
    for (int y = 1; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (wallh[x][y] && rmap[x][y - 1] == rmap[x][y]) {
                cout << "Invalid";
                return 0;
            }
        }
    }
    undirectedgraph<int> g(rcnt);
    set<pair<int, int>> edges;
    auto add = [&](int r1, int r2) {
        if (r1 != -1 && r2 != -1 && r1 != r2) {
            int u = min(r1, r2);
            int v = max(r1, r2);
            if (edges.find({u, v}) == edges.end()) {
                g.add(u, v);
                edges.insert({u, v});
            }
        }
    };
    for (int x = 1; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (wallv[x][y]) {
                add(rmap[x - 1][y], rmap[x][y]);
            }
        }
    }
    for (int y = 1; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (wallh[x][y]) {
                add(rmap[x][y - 1], rmap[x][y]);
            }
        }
    }
    auto match = find_max_unweighted_matching(g);
    long long match_edges = count_if(match.begin(), match.end(), [](int x) { return x != -1; }) / 2;
    long long ans = rcnt - match_edges;
    cout << ans;
    return 0;
}
