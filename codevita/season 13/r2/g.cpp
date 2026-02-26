#include <bits/stdc++.h>
using namespace std;
constexpr long long INF = 4e18;
long long get_hand_cost(int deg, long long r1, long long r2) {
    if (deg <= 90) return deg * r1;
    return 90 * r1 + (deg - 90) * r2;
}
int get_dist_cw(int s, int e) { return (e - s + 360) % 360; }
int get_dist_ccw(int s, int e) { return (s - e + 360) % 360; }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, m;
    char colon;
    cin >> h >> colon >> m;
    int n;
    cin >> n;
    long long a, b, p, q, x, y;
    cin >> a >> b;
    cin >> p >> q;
    cin >> x >> y;
    vector<int> queries(n);
    for (int i = 0; i < n; i++) {
        cin >> queries[i];
    }
    int curH = (h % 12) * 30;
    int curM = m * 6;
    long long ans = 0;
    for (int tangle : queries) {
        long long min_cost = INF;
        int bestH = -1, bestM = -1;
        int diff = (tangle == 360) ? 0 : tangle;
        for (int i = 0; i < 12; i++) {
            int nextH = i * 30;
            for (int nextM : {(nextH - diff + 360) % 360, (nextH + diff) % 360}) {
                {
                    int dH = get_dist_cw(curH, nextH);
                    int dM = get_dist_ccw(curM, nextM);
                    int safe_gap = get_dist_cw(curH, curM);
                    if (curH == curM) safe_gap = 360;
                    if (dH + dM <= safe_gap) {
                        long long cost = get_hand_cost(dH, p, q) * a + get_hand_cost(dM, x, y) * b;
                        if (cost < min_cost) {
                            min_cost = cost;
                            bestH = nextH;
                            bestM = nextM;
                        }
                    }
                }
                {
                    int dH = get_dist_ccw(curH, nextH);
                    int dM = get_dist_cw(curM, nextM);
                    int safe_gap = get_dist_ccw(curH, curM);
                    if (curH == curM) safe_gap = 360;
                    if (dH + dM <= safe_gap) {
                        long long cost = get_hand_cost(dH, p, q) * b + get_hand_cost(dM, x, y) * a;
                        if (cost < min_cost) {
                            min_cost = cost;
                            bestH = nextH;
                            bestM = nextM;
                        }
                    }
                }
            }
        }
        ans += min_cost;
        curH = bestH;
        curM = bestM;
    }
    cout << ans;
    return 0;
}