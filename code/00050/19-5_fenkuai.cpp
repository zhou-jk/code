// AC
#include <cmath>
#include <cstdio>

using std::printf;
using std::scanf;
using std::sqrt;

const int N = 200000;
int a[N], belong[N], f[N], to[N], n;

void build() {
    int size = sqrt(n);
    for (int i = 0; i < n; ++i) belong[i] = i / size;
    for (int i = n - 1; ~i; --i) {
        int v = i + a[i];
        if (v >= n || belong[i] != belong[v]) {
            f[i] = 1;
            to[i] = v;
        } else {
            f[i] = f[v] + 1;
            to[i] = to[v];
        }
    }
}

int main() {
    int q;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    build();
    scanf("%d", &q);
    while (q--) {
        int op, k;
        scanf("%d%d", &op, &k);
        if (op == 1) {
            int ans = 0;
            while (k < n) {
                ans += f[k];
                k = to[k];
            }
            printf("%d\n", ans);
        } else {
            scanf("%d", a + k);
            for (int i = k; ~i && belong[i] == belong[k]; --i) {
                int v = i + a[i];
                if (v >= n || belong[i] != belong[v]) {
                    f[i] = 1;
                    to[i] = v;
                } else {
                    f[i] = f[v] + 1;
                    to[i] = to[v];
                }
            }
        }
    }
    return 0;
}