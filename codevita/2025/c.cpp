#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<set<pair<int, int>>> sp(n);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int dx = x2 - x1, dy = y2 - y1;
        int stepx = (dx > 0 ? 1 : (dx < 0 ? -1 : 0));
        int stepy = (dy > 0 ? 1 : (dy < 0 ? -1 : 0));
        set<pair<int, int>>& pts = sp[i];
        int cx = x1, cy = y1;
        pts.insert({cx, cy});
        for (int k = 1; k <= abs(dx); k++) {
            cx += stepx;
            cy += stepy;
            pts.insert({cx, cy});
        }
    }
    int sx, sy;
    cin >> sx >> sy;
    pair<int, int> pos = {sx, sy};
    auto cover_count = [&](pair<int, int> p) -> int {
        int c = 0;
        for (int i = 0; i < n; i++)
            if (sp[i].count(p)) c++;
        return c;
    };
    auto on_which_seg = [&](pair<int, int> p) -> int {
        for (int i = 0; i < n; i++)
            if (sp[i].count(p)) return i;
        return -1;
    };
    auto find_next_hit = [&](int x, int max_y) -> pair<int, int> {
        for (int ty = max_y; ty >= 1; --ty) {
            for (int s = 0; s < (int)sp.size(); s++) {
                if (sp[s].count({x, ty})) return {x, ty};
            }
        }
        return {x, 0};
    };
    auto slide_func = [&](int s, pair<int, int> start_pos) -> pair<pair<int, int>, bool> {
        pair<int, int> cur = start_pos;
        if (cover_count(cur) >= 2) return {cur, true};
        while (true) {
            pair<int, int> nextp;
            bool has = false;
            if (cur.second - 1 >= 0) {
                if (sp[s].count({cur.first - 1, cur.second - 1})) {
                    nextp = {cur.first - 1, cur.second - 1};
                    has = true;
                } else if (sp[s].count({cur.first + 1, cur.second - 1})) {
                    nextp = {cur.first + 1, cur.second - 1};
                    has = true;
                }
            }
            if (!has) {
                return {cur, false};
            }
            cur = nextp;
            if (cur.second == 0) return {cur, false};
            if (cover_count(cur) >= 2) return {cur, true};
        }
    };
    while (pos.second > 0) {
        if (cover_count(pos) >= 2) break;
        int hs = on_which_seg(pos);
        bool can_slide_now = false;
        if (hs != -1) {
            if (sp[hs].count({pos.first - 1, pos.second - 1}) ||
                sp[hs].count({pos.first + 1, pos.second - 1})) {
                can_slide_now = true;
            }
        }
        if (can_slide_now) {
            auto res = slide_func(hs, pos);
            pos = res.first;
            if (res.second) break;
            if (pos.second == 0) break;
            continue;
        }
        auto nh = find_next_hit(pos.first, pos.second - 1);
        pos = nh;
        if (pos.second == 0) break;
        if (cover_count(pos) >= 2) break;
    }
    cout << pos.first << " " << pos.second;
    return 0;
}
