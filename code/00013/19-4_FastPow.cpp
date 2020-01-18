// AC
#include <cstdio>

typedef long long ll;

const int P = 100003;

int pow(int a, ll b) {
    int ret = 1 % P;
    a %= P;
    while (b) {
        if (b & 1) ret = (ll)ret * a % P;
        a = (ll)a * a % P;
        b >>= 1;
    }
    return ret;
}

int main() {
    int m;
    ll n;
    scanf("%d%lld", &m, &n);
    printf("%lld", ((pow(m, n) - (ll)m * pow(m - 1, n - 1)) % P + P) % P);
    return 0;
}