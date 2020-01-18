// AC
#include <cstdio>

const int N = 12, S = 1 << N, P = 1E8;
int a[N], b[S], c[N][S], cnt2[N], f[N][S];

int main() {
    freopen("akali.in", "r", stdin);
    freopen("akali.out", "w", stdout);
    int n, m, cnt1 = 0, ans = 0;
    scanf("%d%d", &n, &m);
    int s = 1 << m;
    for (int i = 0; i < s; ++i)
        if (!(i & (i << 1))) b[cnt1++] = i;
    // printf("%d\n", cnt1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int tmp;
            scanf("%d", &tmp);
            a[i] |= tmp << j;
        }
    for (int i = 0; i < cnt1; ++i)
        if ((b[i] | a[0]) == a[0]) {
            c[0][cnt2[0]] = b[i];
            f[0][cnt2[0]++] = 1 % P;
        }
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < cnt1; ++j)
            if ((b[j] | a[i]) == a[i]) {
                c[i][cnt2[i]++] = b[j];
                for (int k = 0; k < cnt2[i - 1]; ++k)
                    if (!(b[j] & c[i - 1][k]))
                        f[i][cnt2[i] - 1] =
                            (f[i][cnt2[i] - 1] + f[i - 1][k]) % P;
            }
    for (int i = 0; i < cnt2[n - 1]; ++i) {
        ans = (ans + f[n - 1][i]) % P;
        // printf("%d %d\n", i, f[n - 1][i]);
    }
    printf("%d", ans);
    return 0;
}