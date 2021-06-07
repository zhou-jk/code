#include <cstdio>
#include <vector>
#include <functional>
const int MOD = 998244353;

int main() {
    int n, s;
    scanf("%d%d", &n, &s);
    std::vector<int>a(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int ans = 0;
    std::function<void(int, int)>solve = [&](int l, int r) {
        if (l == r) {
            if (a[l] == s)
                ans = (ans + 1) % MOD;

            return;
        }

        int mid = (l + r) / 2;
        solve(l, mid);
        solve(mid + 1, r);
        std::vector<int>f(s + 1), pre(s + 1);
        f[0] = 1;

        for (int i = mid; i >= l; i--) {
            for (int j = s; j >= a[i]; j--)
                f[j] = (f[j] + f[j - a[i]]) % MOD;

            for (int j = 0; j <= s; j++)
                pre[j] = (pre[j] + f[j]) % MOD;
        }

        std::vector<int>g(s + 1), nxt(s + 1);
        g[0] = 1;

        for (int i = mid + 1; i <= r; i++) {
            for (int j = s; j >= a[i]; j--)
                g[j] = (g[j] + g[j - a[i]]) % MOD;

            for (int j = 0; j <= s; j++)
                nxt[j] = (nxt[j] + g[j]) % MOD;
        }

        for (int i = 0; i <= s; i++)
            ans = (ans + (long long)pre[i] * nxt[s - i]) % MOD;

        return;
    };
    solve(0, n - 1);
    printf("%d", ans);
    return 0;
}