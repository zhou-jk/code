// AC
#include <algorithm>
#include <cstdio>

using std::max;

const int N = 30, M = 10, V = 200;
int a[M][N], w[N], c[N], cnt[M], f[V + 1];

int main() {
    int v, n, m;
    scanf("%d%d%d", &v, &n, &m);
    for (int i = 0; i < n; ++i) {
        int p;
        scanf("%d%d%d", w + i, c + i, &p);
        --p;
        a[p][cnt[p]++] = i;
    }
    for (int i = 0; i < m; ++i)
        for (int j = v; ~j; --j)
            for (int k = 0; k < cnt[i]; ++k) {
                int p = a[i][k];
                if (j >= w[p]) f[j] = max(f[j], f[j - w[p]] + c[p]);
            }
    printf("%d", f[v]);
    return 0;
}