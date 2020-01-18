// AC
#include <algorithm>
#include <cmath>
#include <cstdio>

using std::max;

const int N = 15;
int c[N], p[N], l[N], n;

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

bool check(int ans) {
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            int a = p[i] - p[j], b = ans, cc = c[j] - c[i], d, x, y;
            d = exgcd(a, b, x, y);
            if (cc % d) continue;
            b /= d;
            cc /= d;
            b = abs(b);
            x = (x * cc % b + b) % b;
            if (x <= l[i] && x <= l[j]) return 0;
        }
    return 1;
}

int main() {
    int ss = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", c + i, p + i, l + i);
        ss = max(ss, c[i]);
    }
    for (int i = ss;; ++i)
        if (check(i)) {
            printf("%d", i);
            break;
        }
    return 0;
}