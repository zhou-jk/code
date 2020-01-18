#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

using std::lower_bound;
using std::upper_bound;
using std::vector;

const int N = 200000, M = sqrt(N);
int prime[90], f[N + 1][90], cnt;
bool isPrime[M + 1];
vector<int> s[N + 1];

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    for (int i = 2; i <= M; ++i)
        if (!isPrime[i]) {
            prime[cnt++] = i;
            for (int j = i << 1; j <= M; j += i) isPrime[j] = true;
        }
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        int a;
        scanf("%d", &a);
        for (int j = 0; j < cnt; ++j) {
            f[i][j] = f[i - 1][j];
            while (!(a % prime[j])) {
                ++f[i][j];
                a /= prime[j];
            }
        }
        if (a > 1) s[a].push_back(i);
    }
    while (q--) {
        int l, r, a;
        bool flag = false;
        scanf("%d%d%d", &l, &r, &a);
        for (int i = 0; i < cnt; ++i) {
            int cnt1 = 0;
            while (!(a % prime[i])) {
                ++cnt1;
                a /= prime[i];
            }
            if (f[r][i] - f[l - 1][i] < cnt1) {
                flag = true;
                break;
            }
        }
        puts(flag || (a > 1 && upper_bound(s[a].begin(), s[a].end(), r) ==
                                   lower_bound(s[a].begin(), s[a].end(), l))
                 ? "No"
                 : "Yes");
    }
    return 0;
}
