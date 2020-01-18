// AC
#include <cstdio>

const int N = 4, K = 1000, c[N] = {10, 20, 50, 100};
int f[K + 1];

int main() {
    int k;
    scanf("%d", &k);
    f[0] = 1;
    for (int i = 0; i < N; ++i)
        for (int j = c[i]; j <= k; ++j) f[j] += f[j - c[i]];
    printf("%d", f[k]);
    return 0;
}