#include <bits/stdc++.h>
using namespace std;
int k, n;
int startX, startY;
int X1, Y1, X2, Y2;
struct State {
    int bx;
    int dx;
    int score;
    int paddlec;
    State(int _bx, int _dx, int _score, int _paddlec) : bx(_bx), dx(_dx), score(_score), paddlec(_paddlec) {}
};
bool visited[30][30][2][30];
tuple<bool, int, int, int> bfs(int x, int y, int dx, int dy, int cur) {
    int cx = x, cy = y;
    int cdx = dx, cdy = dy;
    int score = cur;
    while (true) {
        if (score >= k && cy > Y1) return {true, 0, 0, score};
        int nx = cx + cdx;
        int ny = cy + cdy;
        bool hit_left = (nx <= X1);
        bool hit_right = (nx >= X2);
        bool hit_top = (ny >= Y2);
        bool hit_bottom = (ny <= Y1);
        if ((hit_left || hit_right) && (hit_top || hit_bottom)) {
            if (hit_top) {
                score += 2;
                cdx = -cdx;
                cdy = -cdy;
                cx = nx;
                cy = ny;
                continue;
            }
            if (hit_bottom) {
                score += 1;
                return {false, nx, cdx, score};
            }
        }
        if (hit_top) {
            score += 1;
            cdy = -cdy;
            cx = nx;
            cy = ny;
            continue;
        }
        if (hit_left || hit_right) {
            score += 1;
            cdx = -cdx;
            cx = nx;
            cy = ny;
            continue;
        }
        if (hit_bottom) {
            return {false, nx, cdx, score};
        }
        cx = nx;
        cy = ny;
    }
    return {false, cx, cdx, score};
}

bool check(int limit) {
    memset(visited, 0, sizeof(visited));
    queue<State> q;
    auto [success, bx, dx, score] = bfs(startX, startY, -1, 1, 0);
    if (success) return true;
    int dx_idx = (dx == -1) ? 0 : 1;
    score = min(score, k + 2);
    q.push({bx, dx, score, startX});
    visited[score][bx][dx_idx][startX] = true;
    while (!q.empty()) {
        State u = q.front();
        q.pop();
        int stc = max({X1 + n / 2, u.paddlec - limit, u.bx - n / 2});
        int edc = min({X2 - n / 2, u.paddlec + limit, u.bx + n / 2});
        if (stc > edc) continue;
        if (u.score >= k) return true;
        for (int nc = stc; nc <= edc; nc++) {
            int ndx = u.dx;
            int ndy = 1;
            if (u.bx == nc - n / 2) {
                ndx = -1;
            } else if (u.bx == nc + n / 2) {
                ndx = 1;
            }
            auto [next_success, next_bx, next_dx, next_score] = bfs(u.bx, Y1, ndx, ndy, u.score);
            if (next_success) return true;
            int next_dx_idx = (next_dx == -1) ? 0 : 1;
            next_score = min(next_score, k + 2);
            if (!visited[next_score][next_bx][next_dx_idx][nc]) {
                visited[next_score][next_bx][next_dx_idx][nc] = true;
                q.emplace(next_bx, next_dx, next_score, nc);
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k;
    cin >> startX >> startY;
    cin >> n;
    cin >> X1 >> Y1 >> X2 >> Y2;
    int l = 0, r = max(X2, Y2) * 2;
    int ans = r;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid, r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}