#include <bits/stdc++.h>
using namespace std;
constexpr int N = 200005;
int n;
int a[N], b[N];
int prea[N], preb[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 2; i <= n; i++) prea[i] = max(prea[i - 1], a[i]), preb[i] = max(preb[i - 1], b[i]);
    map<int, long long> cnt;
    cnt[a[1]]++;
    for (int i = 2; i <= n; i++) {
        int rb = upper_bound(preb + 2, preb + n + 1, prea[i]) - preb - 2;
        cnt[prea[i]] += rb;
        int ra = lower_bound(prea + 2, prea + n + 1, preb[i]) - prea - 2;
        cnt[preb[i]] += ra;
        cnt[a[i]]++, cnt[b[i]]++;
    }
    long long mx = 0, mxnum = 0;
    for (auto [v, num] : cnt)
        if (num > mxnum)
            mxnum = num, mx = v;
        else if (num == mxnum && v > mx)
            mx = v;
    cout << mx << " " << mxnum << "\n";
    return 0;
}