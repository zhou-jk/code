#include <bits/stdc++.h>
using namespace std;
constexpr long long INF = LLONG_MAX;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string t;
    cin >> t;
    int X, Y;
    cin >> X >> Y;
    int H = (t[0] - '0') * 10 + (t[1] - '0');
    int M = (t[3] - '0') * 10 + (t[4] - '0');
    int orig_d[4] = {H / 10, H % 10, M / 10, M % 10};
    int seg[10] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};
    int orig_mask[4];
    for (int i = 0; i < 4; i++) orig_mask[i] = seg[orig_d[i]];
    long long min_cost = INF;
    string best = "";
    for (int pos = 0; pos < 4; pos++) {
        for (int bit = 0; bit < 7; bit++) {
            int new_masks[4];
            for (int j = 0; j < 4; j++) new_masks[j] = orig_mask[j];
            new_masks[pos] ^= (1 << bit);
            int new_d[4];
            bool valid = true;
            for (int j = 0; j < 4; j++) {
                bool matched = false;
                for (int dd = 0; dd < 10; dd++) {
                    if (seg[dd] == new_masks[j]) {
                        new_d[j] = dd;
                        matched = true;
                        break;
                    }
                }
                if (!matched) {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;
            int hh = new_d[0] * 10 + new_d[1];
            int mm = new_d[2] * 10 + new_d[3];
            if (hh < 1 || hh > 12 || mm < 0 || mm > 59) continue;
            int h_mark0 = (H % 12) * 5;
            int h_mark1 = (hh % 12) * 5;
            int h_step = abs(h_mark1 - h_mark0);
            h_step = min(h_step, 60 - h_step);
            int m_step = abs(M - mm);
            m_step = min(m_step, 60 - m_step);
            long long total = 1LL * X * h_step + 1LL * Y * m_step;
            stringstream ss;
            ss << setw(2) << setfill('0') << hh << ":" << setw(2) << setfill('0') << mm;
            string ts = ss.str();
            if (total < min_cost || (total == min_cost && ts < best)) {
                min_cost = total;
                best = ts;
            }
        }
    }
    if (min_cost != INF) {
        cout << best;
    } else {
        cout << "No closest valid time possible";
    }
    return 0;
}