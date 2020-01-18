#include <algorithm>
#include <cstdio>

using std::min;

const int N = 5000;
char s[N + 1];
int f[N + 1][N + 1], g[N + 1];

int main() {
    int n, a, b;
    scanf("%d%d%d%s", &n, &a, &b, s);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            f[i][j] = s[i - 1] == s[j - 1] ? f[i - 1][j - 1] + 1 : 0;
    for (int i = 1; i <= n; ++i) {
        g[i] = g[i - 1] + a;
        for (int j = 1; j < i; ++j)
            if (i - f[i][j] >= j) g[i] = min(g[i], g[i - f[i][j]] + b);
    }
    printf("%d", g[n]);
    return 0;
}