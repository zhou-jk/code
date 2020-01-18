// AC
#include <cstdio>

typedef long long ll;

int n;

int pow(int a, int b) {
    int ret = 1 % n;
    while (b) {
        if (b & 1) ret = (ll)ret * a % n;
        a = (ll)a * a % n;
        b >>= 1;
    }
    return ret;
}

int main() {
    int m, k, x;
    scanf("%d%d%d%d", &n, &m, &k, &x);
    printf("%lld", ((ll)m * pow(10, k) % n + x) % n);
    return 0;
}