#include <bits/stdc++.h>
using namespace std;
constexpr int N = 55;
struct Piece {
    int id;
    int cost;
    set<pair<int, int>> cells;
    int min_r, max_r, min_c, max_c;
};
int n, m;
int grid[N][N];
int tid;
map<int, Piece> pieces;
map<int, set<int>> down;
map<int, set<int>> downby;
bool cols_intersect(int pID, int tID) {
    const Piece& p = pieces[pID];
    const Piece& t = pieces[tID];
    return max(p.min_c, t.min_c) <= min(p.max_c, t.max_c);
}
long long solve(string side) {
    set<int> removed;
    queue<int> q;
    set<int> inq;
    if (side == "left") {
        for (auto [r, c] : pieces[tid].cells) {
            for (int k = c - 1; k >= 0; --k) {
                int id = grid[r][k];
                if (id != 0 && id != tid) {
                    if (removed.find(id) == removed.end()) {
                        removed.insert(id);
                        inq.insert(id);
                        q.push(id);
                    }
                }
            }
        }
    } else if (side == "right") {
        for (auto [r, c] : pieces[tid].cells) {
            for (int k = c + 1; k < m; k++) {
                int id = grid[r][k];
                if (id != 0 && id != tid) {
                    if (removed.find(id) == removed.end()) {
                        removed.insert(id);
                        inq.insert(id);
                        q.push(id);
                    }
                }
            }
        }
    } else if (side == "up") {
        for (auto [r, c] : pieces[tid].cells) {
            for (int k = r - 1; k >= 0; --k) {
                int id = grid[k][c];
                if (id != 0 && id != tid) {
                    if (removed.find(id) == removed.end()) {
                        removed.insert(id);
                        inq.insert(id);
                        q.push(id);
                    }
                }
            }
        }
    } else if (side == "down") {
        for (auto [r, c] : pieces[tid].cells) {
            for (int k = r + 1; k < n; k++) {
                int id = grid[k][c];
                if (id != 0 && id != tid) {
                    if (removed.find(id) == removed.end()) {
                        removed.insert(id);
                        inq.insert(id);
                        q.push(id);
                    }
                }
            }
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        set<int> neighbors;
        for (auto [r, c] : pieces[u].cells) {
            int nr = r, nc = c;
            if (side == "left")
                nc--;
            else if (side == "right")
                nc++;
            else if (side == "up")
                nr--;
            else if (side == "down")
                nr++;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                int nid = grid[nr][nc];
                if (nid != 0 && nid != u && nid != tid) {
                    neighbors.insert(nid);
                }
            }
        }
        for (int v : neighbors) {
            if (removed.find(v) == removed.end()) {
                removed.insert(v);
                if (inq.find(v) == inq.end()) {
                    inq.insert(v);
                    q.push(v);
                }
            }
        }
        if (down.count(u)) {
            for (int v : down[u]) {
                if (v == tid) continue;
                if (removed.find(v) != removed.end()) continue;
                bool stable = false;
                for (int s : downby[v]) {
                    if (removed.find(s) == removed.end()) {
                        stable = true;
                        break;
                    }
                }
                if (!stable) {
                    bool dangerous = false;
                    if (side == "left" || side == "right" || side == "up") {
                        dangerous = true;
                    } else if (side == "down") {
                        if (cols_intersect(v, tid)) {
                            dangerous = true;
                        }
                    }
                    if (dangerous) {
                        removed.insert(v);
                        if (inq.find(v) == inq.end()) {
                            inq.insert(v);
                            q.push(v);
                        }
                    }
                }
            }
        }
    }
    long long total = 0;
    for (int id : removed) {
        total += pieces[id].cost;
    }
    return total;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            int id = grid[i][j];
            if (id != 0) {
                if (pieces.find(id) == pieces.end()) {
                    pieces[id] = {id, id, {}, n, -1, m, -1};
                }
                pieces[id].cells.insert({i, j});
                pieces[id].min_r = min(pieces[id].min_r, i);
                pieces[id].max_r = max(pieces[id].max_r, i);
                pieces[id].min_c = min(pieces[id].min_c, j);
                pieces[id].max_c = max(pieces[id].max_c, j);
            }
        }
    }
    cin >> tid;
    for (auto [id, p] : pieces) {
        for (auto [r, c] : p.cells) {
            if (r + 1 < n) {
                int below = grid[r + 1][c];
                if (below != 0 && below != id) {
                    down[below].insert(id);
                    downby[id].insert(below);
                }
            }
        }
    }
    for (auto& [id, p] : pieces) {
        bool is_on_floor = false;
        for (auto cell : p.cells) {
            if (cell.first == n - 1) {
                is_on_floor = true;
                break;
            }
        }
        if (is_on_floor) {
            downby[id].insert(-1);
        }
    }
    long long min_cost = -1;
    string best_side = "";
    vector<string> sides = {"down", "up", "left", "right"};
    for (const string& side : sides) {
        long long c = solve(side);
        if (min_cost == -1 || c < min_cost) {
            min_cost = c;
            best_side = side;
        }
    }
    cout << min_cost << " via " << best_side;
    return 0;
}