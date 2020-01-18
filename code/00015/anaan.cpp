//AC
#include <cstdio>

typedef long long ll;

const int K = 10000;
int k;
ll a[K + 1], b[K + 1], n, m, xx;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll mul(ll a, ll b, ll p) {
    ll ret = 0;
    for (; b; b >>= 1, a = (a << 1) % p)
        if (b & 1) ret = (ret + a) % p;
    return ret;
}

ll excrt() {
    ll ans = b[1], lcm = a[1], x, y;
    for (int i = 2; i <= k; ++i) {
        ll tmpa = a[i], c = (b[i] - ans % tmpa + tmpa) % tmpa, d;
        d = exgcd(lcm, tmpa, x, y);
        if (c % d) return -1;
        tmpa /= d;
        if (lcm > n / tmpa) return -1;
        x = (mul(x, c / d, tmpa) + tmpa) % tmpa;
        ans += lcm * x;
        lcm *= tmpa;
        ans %= lcm;
    }
    xx = lcm;
    return ans ? ans : lcm;
}

int main() {
    freopen("anaan.in", "r", stdin);
    freopen("anaan.out", "w", stdout);
    ll yy;
    scanf("%lld%lld%d", &n, &m, &k);
    for (int i = 1; i <= k; ++i) {
        scanf("%lld", a + i);
        b[i] = ((-i + 1) % a[i] + a[i]) % a[i];
    }
    if ((yy = excrt()) == -1) {
        puts("NO");
        return 0;
    }
    // printf("%lld %lld\n",xx,yy);
    if (yy > m - k + 1) {
        puts("NO");
        return 0;
    }
    for (int i = 1; i <= k; ++i)
        if (gcd(xx, yy + i - 1) != a[i]) {
            puts("NO");
            return 0;
        }
    puts("YES");
    return 0;
}
