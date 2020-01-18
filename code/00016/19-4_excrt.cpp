//AC
#include <cstdio>

typedef long long ll;

const int N = 100000;
ll a[N], p[N];
int n;

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
    ll ans = a[0], lcm = p[0], x, y;
    for (int i = 1; i < n; ++i) {
        ll b = p[i], c = (a[i] - ans % b + b) % b, d;
        d = exgcd(lcm, b, x, y);
        if (c % d) return -1;
        b /= d;
        x = (mul(x, c / d, b) + b) % b;
        ans += lcm * x;
        lcm *= b;
        ans %= lcm;
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i) scanf("%lld%lld",p+i,a+i);
    printf("%lld",excrt());
    return 0;
}