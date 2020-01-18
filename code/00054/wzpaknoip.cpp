// AC
#include <cmath>
#include <cstdio>

using std::abs;

const int N = 100000, dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
char s[N + 1];
int sumX[N + 1], sumY[N + 1], n, xo, yo, xx, yy;

inline int covert(char ch) {
    switch (ch) {
        case 'U':
            return 0;
            break;
        case 'L':
            return 1;
            break;
        case 'D':
            return 2;
            break;
        case 'R':
            return 3;
            break;
        default:
            return -1;
            break;
    }
}

bool check(long long a) {
    long long tmp1 = a / n, tmp2 = a % n;
    long long tx = xo + sumX[n] * tmp1 + sumX[tmp2];
    long long ty = yo + sumY[n] * tmp1 + sumY[tmp2];
    return abs(xx - tx) + abs(yy - ty) <= a;
}

int main() {
    freopen("wzpaknoip.in", "r", stdin);
    freopen("wzpaknoip.out", "w", stdout);
    scanf("%d%d%d%d%d%s", &xo, &yo, &xx, &yy, &n, s);
    for (int i = 0; i < n; ++i) {
        int dir = covert(s[i]);
        sumX[i + 1] = sumX[i] + dx[dir];
        sumY[i + 1] = sumY[i] + dy[dir];
    }
    long long l = 0, r = 1E18;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%lld", l > 1000000000000000000 ? -1 : l);
    return 0;
}
