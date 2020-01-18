// AC
#include <cstdio>

const int N = 500;
int c[N][N], sum[N + 1][N + 1], n, m, a, b;

bool check(int num) {
    int cnt1 = 0;
    for (int i = 1, j = 0; i <= n; ++i) {
        int cnt2 = 0;
        for (int k = 1, p = 0; k <= m; ++k)
            if (sum[i][k] - sum[i][p] - sum[j][k] + sum[j][p] >= num) {
                ++cnt2;
                p = k;
            }
        if (cnt2 >= b) {
            ++cnt1;
            j = i;
        }
    }
    return cnt1 >= a;
}

int main() {
    freopen("browine.in", "r", stdin);
    freopen("browine.out", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &a, &b);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            scanf("%d", &c[i][j]);
            sum[i + 1][j + 1] =
                sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + c[i][j];
        }
    int l = 0, r = sum[n][m];
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("%d", r);
    return 0;
}
