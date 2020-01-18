// AC
#include <cstdio>

const int K = 1000;
int f[K + 1];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    f[0] = 1;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        for (int j = k; j >= a; --j) f[j] += f[j - a];
    }
    printf("%d", f[k]);
    return 0;
}