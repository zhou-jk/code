// AC
#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;

const int A = 21, B = 79;
int f[A + 1][B + 1];

int main() {
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    memset(f, 63, sizeof f);
    f[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int a_, b_, v;
        scanf("%d%d%d", &a_, &b_, &v);
        for (int j = a; ~j; --j)
            for (int k = b; ~k; --k) {
                int _a = min(j + a_, a), _b = min(k + b_, b);
                f[_a][_b] = min(f[_a][_b], f[j][k] + v);
            }
    }
    printf("%d", f[a][b]);
    return 0;
}