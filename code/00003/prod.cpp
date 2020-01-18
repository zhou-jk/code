#include <algorithm>
#include <cctype>
#include <cstdio>

using std::min;

const int N = 1000;
int a[N][N], b[N][N], f[N][N], n;

inline char get_char() {
    static const int SIZE = 1 << 20;
    static char buf[SIZE], *s, *t;
    if (s == t) {
        t = (s = buf) + fread(buf, 1, SIZE, stdin);
        if (s == t) return EOF;
    }
    return *s++;
}

#define getchar get_char

inline int get_int() {
    char c;
    int ret = 0;
    for (c = getchar(); !isdigit(c); c = getchar())
        ;
    for (; isdigit(c); c = getchar()) ret = (ret << 1) + (ret << 3) + (c ^ 48);
    return ret;
}

int solve(int s) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!a[i][j])
                b[i][j] = 1E6;
            else {
                int tmp = a[i][j];
                b[i][j] = 0;
                while (!(tmp % s)) {
                    tmp /= s;
                    ++b[i][j];
                }
            }
    f[0][0] = b[0][0];
    for (int i = 1; i < n; ++i) {
        f[i][0] = f[i - 1][0] + b[i][0];
        f[0][i] = f[0][i - 1] + b[0][i];
    }
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j)
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + b[i][j];
    return f[n - 1][n - 1];
}

int main() {
    freopen("prod.in", "r", stdin);
    freopen("prod.out", "w", stdout);
    n = get_int();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) a[i][j] = get_int();
    printf("%d", min(solve(2), solve(5)));
    return 0;
}
