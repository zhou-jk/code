#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 300005;
int n, m;
int cx[N], cy[N];
int hx[N], hy[N];
bool check(int x) {
    int lux = -2e9, luy = -2e9, rdx = 2e9, rdy = 2e9;
    for (int i = 1; i <= n; i++) {
        int x1 = cx[i] - x, y1 = cy[i] - x, x2 = cx[i] + x, y2 = cy[i] + x;
        // cerr << "center" << cx[i] << " " << cy[i] << "\n";
        // cerr << "x1=" << x1 << " y1=" << y1 << " x2=" << x2 << " y2=" << y2 << "\n";
        if (x1 > x2 || y1 > y2) continue;
        lux = max(lux, x1);
        luy = max(luy, y1);
        rdx = min(rdx, x2);
        rdy = min(rdy, y2);
    }
    if (lux > rdx || luy > rdy) return false;
    for (int i = 1; i <= m; i++) {
        if (hx[i] >= lux && hx[i] <= rdx && hy[i] >= luy && hy[i] <= rdy) {
            return true;
        }
    }
    return false;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        cx[i] = x + y;
        cy[i] = x - y;
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        hx[i] = x + y;
        hy[i] = x - y;
    }
    int l = 0, r = 2e9, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    cout << ans << "\n";
}
signed main() {
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}