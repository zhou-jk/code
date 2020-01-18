// AC
#include <cstdio>

const int N = 10;
int f[N + 1][N + 1];

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= N; ++i) f[i][1] = 1;
    for (int i = 1; i <= N; ++i) f[0][i] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 2; j <= N; ++j)
            f[i][j] = i < j ? f[i][i] : f[i][j - 1] + f[i - j][j];
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        printf("%d\n", f[n][m]);
    }
    return 0;
}