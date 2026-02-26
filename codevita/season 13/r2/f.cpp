#include <bits/stdc++.h>
using namespace std;
constexpr int P = 26;
constexpr int T = 50;
pair<int, int> dist(int radius, int t) {
    int d = radius - 1;
    if (d <= 0) return {0, 0};
    int L = 8 * d;
    int idx = (7 * d + (t % L)) % L;
    if (idx < 2 * d) {
        int x = d - idx;
        int y = -d;
        return {x, y};
    } else if (idx < 4 * d) {
        int k = idx - 2 * d;
        int x = -d;
        int y = -d + k;
        return {x, y};
    } else if (idx < 6 * d) {
        int k = idx - 4 * d;
        int x = -d + k;
        int y = d;
        return {x, y};
    } else {
        int k = idx - 6 * d;
        int x = d;
        int y = d - k;
        return {x, y};
    }
}
struct State {
    int x, y, t;
    bool operator<(const State& rhs) const {
        if (x != rhs.x) return x < rhs.x;
        if (y != rhs.y) return y < rhs.y;
        return t < rhs.t;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> primary(P, -1);
    vector<int> radius(P, 0);
    vector<vector<int>> children(P);
    vector<bool> exists(P, false);
    for (int i = 0; i < n; i++) {
        char s_c, p_c;
        int r;
        cin >> s_c >> p_c >> r;
        int s = s_c - 'A';
        int p = p_c - 'A';
        exists[s] = exists[p] = true;
        primary[s] = p;
        radius[s] = r;
        children[p].push_back(s);
    }
    char src_c, dst_c;
    cin >> src_c >> dst_c;
    int src = src_c - 'A';
    int dst = dst_c - 'A';
    exists[src] = true;
    exists[dst] = true;
    int root = -1;
    for (int i = 0; i < P; i++) {
        if (exists[i] && primary[i] == -1) {
            root = i;
            break;
        }
    }
    vector<vector<pair<int, int>>> pos(P, vector<pair<int, int>>(T + 1, {0, 0}));
    for (int t = 0; t <= T; t++) {
        pos[root][t] = {0, 0};
    }
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : children[u]) {
            for (int t = 0; t <= T; t++) {
                auto [dx, dy] = dist(radius[v], t);
                pos[v][t].first = pos[u][t].first + dx;
                pos[v][t].second = pos[u][t].second + dy;
            }
            q.push(v);
        }
    }
    if (src == dst) {
        cout << 0 << "\n";
        return 0;
    }
    const auto& destPos = pos[dst];
    auto startP = pos[src][0];
    State start{startP.first, startP.second, 0};
    queue<State> dq;
    dq.push(start);
    set<State> visited;
    visited.insert(start);
    const int moves[5][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {0, 0}};
    int ans = -1;
    while (!dq.empty()) {
        State cur = dq.front();
        dq.pop();
        if (cur.x == destPos[cur.t].first && cur.y == destPos[cur.t].second) {
            ans = cur.t;
            break;
        }
        if (cur.t == T) continue;
        for (int k = 0; k < 5; k++) {
            State nxt{cur.x + moves[k][0], cur.y + moves[k][1], cur.t + 1};
            if (visited.find(nxt) != visited.end()) continue;
            visited.insert(nxt);
            dq.push(nxt);
        }
    }
    if (ans == -1) assert(false);
    cout << ans;
    return 0;
}
