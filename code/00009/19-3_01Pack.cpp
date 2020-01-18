// AC
#include <algorithm>
#include <cstdio>

using std::max;

const int M = 20000;
int f[M + 1];

int main() {
    int n, m;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; ++i) {
        int c;
        scanf("%d", &c);
        for (int j = m; j >= c; --j) f[j] = max(f[j], f[j - c] + c);
    }
    printf("%d", m - f[m]);
    return 0;
}