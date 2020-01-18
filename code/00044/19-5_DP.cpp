// AC
#include <cstdio>

const int N = 1000, M = 200, P = 1000000007;
int f[2][M + 1][M + 1][2];
char a[N + 1], b[M + 1];

inline int Add(int a, int b) {
    int ret = a + b;
    return ret >= P ? ret - P : ret;
}

int main() {
    int n, m, k;
    scanf("%d%d%d%s%s", &n, &m, &k, a, b);
    f[0][0][0][0] = f[1][0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        int now = i & 1, last = (i & 1) ^ 1;
        for (int j = 1; j <= k; ++j)
            for (int p = 1; p <= m; ++p) {
                f[now][j][p][0] = Add(f[last][j][p][0], f[last][j][p][1]);
                if (a[i] == b[p - 1])
                    f[now][j][p][1] =
                        Add(Add(f[last][j - 1][p - 1][0], f[last][j][p - 1][1]),
                            f[last][j - 1][p - 1][1]);
                else
                    f[now][j][p][1] = 0;
            }
    }
    printf("%d", Add(f[(n - 1) & 1][k][m][0], f[(n - 1) & 1][k][m][1]));
    return 0;
}