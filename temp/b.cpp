#include <bits/stdc++.h>
using namespace std;
constexpr int N = 400005;
constexpr int INF = 1e9;
int n, m;
vector<pair<int, int>> g[N];
int lvl[N];
bool vis[N];
int dis[N], ans[N];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) g[i].clear();
    fill(lvl + 1, lvl + n + 1, 26);
    for (int i = 1; i <= m; i++) {
        int u, v;
        char ch;
        cin >> u >> v >> ch;
        int c = ch - 'a';
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
        lvl[u] = min(lvl[u], c);
        lvl[v] = min(lvl[v], c);
    }
    fill(ans + 1, ans + n + 1, INF);
    ans[1] = 0;
    int base = 0;
    int cur = lvl[1];
    vector<int> src = {1};
    fill(dis + 1, dis + n + 1, INF);
    fill(vis + 1, vis + n + 1, false);
    while (!src.empty()) {
        queue<int> q;
        vector<int> touched;
        for (int s : src) {
            if (dis[s] == INF) {
                dis[s] = 0;
                q.push(s);
                touched.emplace_back(s);
            }
            if (ans[s] == INF) ans[s] = base;
        }
        int exit = INF;
        int nlv = 26;
        vector<int> nxt;
        vector<int> marked;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (exit != INF && dis[u] >= exit) continue;
            if (ans[u] == INF) ans[u] = base + dis[u];
            for (auto [v, lab] : g[u]) {
                if (lab != cur) continue;
                if (lvl[v] == cur) {
                    if (dis[v] == INF) {
                        dis[v] = dis[u] + 1;
                        q.push(v);
                        touched.emplace_back(v);
                        if (ans[v] == INF) ans[v] = base + (dis[u] + 1);
                    }
                } else if (lvl[v] < cur) {
                    int t = dis[u] + 1;
                    if (exit == INF) exit = t;
                    if (t == exit) {
                        if (ans[v] == INF) ans[v] = base + t;
                        int lv = lvl[v];
                        if (lv < nlv) {
                            nlv = lv;
                            for (int x : marked) vis[x] = false;
                            marked.clear();
                            nxt.clear();
                        }
                        if (lv == nlv && !vis[v]) {
                            vis[v] = true;
                            marked.emplace_back(v);
                            nxt.emplace_back(v);
                        }
                    }
                }
            }
        }
        for (int x : touched) dis[x] = INF;
        for (int x : marked) vis[x] = false;
        if (exit == INF) break;
        base += exit;
        cur = nlv;
        src.swap(nxt);
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] == INF) ans[i] = -1;
        cout << ans[i] << " \n"[i == n];
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

/*
2
1 0
2 2
1 1 a
2 1 b

2
7 7
1 2 a
1 3 a
2 4 b
3 5 a
5 6 a
6 7 a
7 4 a
4 3
1 2 z
2 3 x
3 4 y
*/