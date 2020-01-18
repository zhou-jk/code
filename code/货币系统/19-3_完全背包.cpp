// AC
#include <cstdio>

const int K = 10000;
long long f[K + 1];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    f[0] = 1;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        for (int j = a; j <= k; ++j) f[j] += f[j - a];
    }
    printf("%lld", f[k]);
    return 0;
}