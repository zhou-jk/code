#include <cstdio>
#include <cmath>
#include <ctime>
#include <vector>
#include <random>
#include <functional>
#include <algorithm>
namespace poly_define
{
    const int g = 3;
    const int MOD = 998244353;
    int n;
    int ksm(int a, int b)
    {
        int res = 1;

        while (b)
        {
            if (b & 1)
                res = 1LL * res * a % MOD;

            a = 1LL * a * a % MOD, b >>= 1;
        }

        return res;
    }
    int getinv(int x)
    {
        return ksm(x, MOD - 2);
    }
    std::vector<int> W[2];
    void init_omega(int n)
    {
        for (int len = 1; len <= n; len <<= 1)
        {
            int w = ksm(g, (MOD - 1) / len), iw = getinv(w);
            W[0][len] = W[1][len] = 1;

            for (int k = 1; k < len; k++)
                W[0][len + k] = 1LL * W[0][len + k - 1] * w % MOD, W[1][len + k] = 1LL * W[1][len + k - 1] * iw % MOD;
        }

        return;
    }
    std::vector<int> inv;
    void init_inv(int n)
    {
        inv[1] = 1;

        for (int i = 2; i <= n; i++)
            inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;

        return;
    }
    void init_poly(int _n)
    {
        n = 1;
        while (n <= _n)
            n <<= 1;
        W[0].resize(n * 4 + 1);
        W[1].resize(n * 4 + 1);
        init_omega(n * 2);
        inv.resize(n * 2 + 1);
        init_inv(n * 2);
        return;
    }
    typedef std::vector<int> poly;
    poly operator+(const poly &a, const poly &b)
    {
        poly f = a, g = b;
        int n = std::max(a.size(), b.size());
        f.resize(n), g.resize(n);
        poly c(n);

        for (int i = 0; i < n; i++)
        {
            c[i] = f[i] + g[i];

            if (c[i] >= MOD)
                c[i] -= MOD;
        }

        return c;
    }
    poly operator-(const poly &a, const poly &b)
    {
        poly f = a, g = b;
        int n = std::max(a.size(), b.size());
        f.resize(n), g.resize(n);
        poly c(n);

        for (int i = 0; i < n; i++)
        {
            c[i] = f[i] - g[i];

            if (c[i] < 0)
                c[i] += MOD;
        }

        return c;
    }
    poly operator+(const poly &F, const int &x)
    {
        poly f = F;
        f[0] += x;

        if (f[0] >= MOD)
            f[0] -= MOD;

        return f;
    }
    poly operator+(const int &x, const poly &F)
    {
        poly f = F;
        f[0] += x;

        if (f[0] >= MOD)
            f[0] -= MOD;

        return f;
    }
    poly operator-(const poly &F, const int &x)
    {
        poly f = F;
        f[0] -= x;

        if (f[0] < 0)
            f[0] += MOD;

        return f;
    }
    poly operator-(const int &x, const poly &F)
    {
        poly f = F;
        int n = f.size() - 1;

        for (int i = 0; i <= n; i++)
            f[i] = MOD - f[i];

        f[0] += x;

        if (f[0] >= MOD)
            f[0] -= MOD;

        return f;
    }
    poly ntt(const poly &F, const poly &G, const std::function<int(int, int)> &mul)
    {
        poly f = F, g = G;
        int n = f.size() - 1, m = g.size() - 1;
        m += n, n = 1;

        while (n <= m)
            n <<= 1;

        f.resize(n);
        g.resize(n);
        std::vector<int> rev(n);

        for (int i = 0; i < n; i++)
        {
            rev[i] = rev[i >> 1] >> 1;

            if (i & 1)
                rev[i] |= n >> 1;
        }

        static const int BIT = 15;
        std::function<void(poly &)> dft = [=](poly &F)
        {
            int n = F.size();
            std::vector<unsigned long long> f(n);

            for (int i = 0; i < n; i++)
                f[i] = F[rev[i]];

            for (int len = 2; len <= n; len <<= 1)
            {
                if (len & (1 << BIT))
                {
                    for (int i = 0; i < n; i++)
                        f[i] %= MOD;
                }

                for (int i = 0; i < n; i += len)
                    for (int k = i; k < i + len / 2; k++)
                    {
                        unsigned long long l = f[k];
                        int r = W[0][len + k - i] * f[k + len / 2] % MOD;
                        f[k] = l + r;
                        f[k + len / 2] = l + MOD - r;
                    }
            }

            for (int i = 0; i < n; i++)
                F[i] = f[i] % MOD;

            return;
        };
        dft(f);
        dft(g);

        for (int i = 0; i < n; i++)
            f[i] = mul(f[i], g[i]);

        std::function<void(poly &)> idft = [=](poly &F)
        {
            int n = F.size();
            std::vector<unsigned long long> f(n);

            for (int i = 0; i < n; i++)
                f[i] = F[rev[i]];

            for (int len = 2; len <= n; len <<= 1)
            {
                if (len & (1 << BIT))
                {
                    for (int i = 0; i < n; i++)
                        f[i] %= MOD;
                }

                for (int i = 0; i < n; i += len)
                    for (int k = i; k < i + len / 2; k++)
                    {
                        unsigned long long l = f[k];
                        int r = W[1][len + k - i] * f[k + len / 2] % MOD;
                        f[k] = l + r;
                        f[k + len / 2] = l + MOD - r;
                    }
            }

            for (int i = 0; i < n; i++)
                F[i] = f[i] % MOD;

            int invn = getinv(n);

            for (int i = 0; i < n; i++)
                F[i] = 1LL * F[i] * invn % MOD;

            return;
        };
        idft(f);
        f.resize(m + 1);
        return f;
    }
    poly operator*(const poly &F, const poly &G)
    {
        return ntt(F, G, [=](const int &x, const int &y)
                   { return 1LL * x * y % MOD; });
    }
    poly operator*(const poly &F, const int &x)
    {
        poly f = F;
        int n = f.size() - 1;

        for (int i = 0; i <= n; i++)
            f[i] = 1LL * f[i] * x % MOD;

        return f;
    }
    poly operator*(const int &x, const poly &F)
    {
        poly f = F;
        int n = f.size() - 1;

        for (int i = 0; i <= n; i++)
            f[i] = 1LL * f[i] * x % MOD;

        return f;
    }
    poly getinv(const poly &F)
    {
        poly f = F;
        int m = f.size() - 1;
        int n = 1;

        while (n <= m)
            n <<= 1;

        f.resize(n);
        poly g = {getinv(f[0])};

        for (int m = 2; m <= n; m <<= 1)
        {
            poly t(f.begin(), f.begin() + m);
            g = ntt(t, g, [=](const int &x, const int &y)
                    { return (2 * y - 1LL * y * y % MOD * x % MOD + MOD) % MOD; });
            g.resize(m);
        }

        g.resize(m + 1);
        return g;
    }
    int w;
    struct Complex
    {
        int real, imag;
        bool operator==(const Complex &b) const
        {
            return real == b.real && imag == b.imag;
        }
        Complex operator*(const Complex &b) const
        {
            Complex res;
            res.real = (1LL * real * b.real + 1LL * w * imag % MOD * b.imag) % MOD;
            res.imag = (1LL * real * b.imag + 1LL * imag * b.real) % MOD;
            return res;
        }
        friend Complex ksm(Complex a, int b)
        {
            Complex res = (Complex){
                1, 0};

            while (b)
            {
                if (b & 1)
                    res = res * a;

                a = a * a, b >>= 1;
            }

            return res;
        }
    };
    int cipolla(int n)
    {
        static std::mt19937 myrand(time(NULL));

        if (n == 0)
            return 0;

        std::function<bool(int)> check = [=](const int &n)
        {
            return ksm(n, (MOD - 1) / 2) == 1;
        };

        if (!check(n))
            return -1;

        int a = myrand() % (MOD - 1) + 1;

        while (check((1LL * a * a - n + MOD) % MOD))
            a = myrand() % (MOD - 1) + 1;

        w = (1LL * a * a - n + MOD) % MOD;
        Complex res = ksm((Complex){
                              a, 1},
                          (MOD + 1) / 2);
        return res.real;
    }
    poly sqrt(const poly &F)
    {
        poly f = F;
        int m = f.size() - 1;
        int n = 1;

        while (n <= m)
            n <<= 1;

        f.resize(n);
        int g0 = cipolla(f[0]);
        poly g = {std::min(g0, MOD - g0)};
        int inv2 = getinv(2);

        for (int m = 2; m <= n; m <<= 1)
        {
            poly t(f.begin(), f.begin() + m);
            g.resize(m);
            g = g * inv2 + ntt(t, getinv(g), [=](const int &x, const int &y)
                               { return 1LL * inv2 * x % MOD * y % MOD; });
            g.resize(m);
        }

        g.resize(m + 1);
        return g;
    }
    poly operator/(const poly &F, const poly &G)
    {
        poly f = F, g = G;
        int n = f.size() - 1, m = g.size() - 1;

        if (n < m)
            return poly(n - m + 1);

        reverse(f.begin(), f.end());
        reverse(g.begin(), g.end());
        f.resize(n - m + 1);
        g.resize(n - m + 1);
        poly q = f * getinv(g);
        q.resize(n - m + 1);
        reverse(q.begin(), q.end());
        return q;
    }
    poly operator%(const poly &F, const poly &G)
    {
        poly f = F, g = G, q = f / g;
        int m = g.size() - 1;
        g.resize(m);
        q.resize(m);
        poly c = g * q;
        c.resize(m);
        f.resize(m);
        return f - c;
    }
    poly diff_calc(const poly &F)
    {
        poly f = F;
        int n = f.size() - 1;
        poly g(n);

        for (int i = 1; i <= n; i++)
            g[i - 1] = 1LL * f[i] * i % MOD;

        return g;
    }
    poly inte_calc(const poly &G)
    {
        poly g = G;
        int n = g.size() - 1;
        poly f(n + 2);

        for (int i = 1; i <= n + 1; i++)
            f[i] = 1LL * g[i - 1] * inv[i] % MOD;

        return f;
    }
    poly ln(const poly &F)
    {
        poly f = F;
        int n = f.size() - 1;
        poly g = diff_calc(f) * getinv(f);
        g.resize(n + 1);
        g = inte_calc(g);
        g.resize(n + 1);
        return g;
    }
    poly exp(const poly &F)
    {
        poly f = F;
        int m = f.size() - 1;
        int n = 1;

        while (n <= m)
            n <<= 1;

        f.resize(n);
        poly g = {1};

        for (int m = 2; m <= n; m <<= 1)
        {
            poly t(f.begin(), f.begin() + m);
            poly s = g;
            g.resize(m);
            g = s * (t - ln(g) + (poly){1});
            g.resize(m);
        }

        g.resize(m + 1);
        return g;
    }
    poly pow(const poly &F, const int &k)
    {
        poly f = F;
        int n = f.size() - 1;
        poly g(n + 1);
        int pos = -1;

        for (int i = 0; i <= n; i++)
            if (f[i] > 0)
            {
                g[i] = f[i];
                pos = i;
                break;
            }

        if (pos == -1)
            return g;

        int mu = f[pos], invm = getinv(mu);

        for (int i = 0; i <= n - pos; i++)
            f[i] = 1LL * f[i + pos] * invm % MOD;

        for (int i = n - pos + 1; i <= n; i++)
            f[i] = 0;

        g[pos] = 0;

        if (1LL * pos * k <= n || pos == 0)
        {
            g = exp(k * ln(f));
            int v = ksm(mu, k);

            for (int i = n; i >= pos * k; i--)
                g[i] = 1LL * g[i - pos * k] * v % MOD;

            for (int i = pos * k - 1; i >= 0; i--)
                g[i] = 0;
        }

        return g;
    }
    int poly_calc(const poly &F, const int &x)
    {
        poly f = F;
        int n = f.size() - 1;
        int fc = 1, res = 0;

        for (int i = 0; i <= n; i++)
            res = (res + 1LL * f[i] * fc) % MOD, fc = 1LL * fc * x % MOD;

        return res;
    }
    poly poly_eval(const poly &F, const poly &a)
    {
        poly f = F;
        int m = a.size();
        std::vector<poly> g(m << 2);
        std::function<void(int, int, int)> init_poly_eval = [&](int i, int l, int r)
        {
            if (l == r)
            {
                g[i] = (poly){
                    MOD - a[l], 1};
                return;
            }

            int mid = (l + r) / 2;
            init_poly_eval(i * 2, l, mid);
            init_poly_eval(i * 2 + 1, mid + 1, r);
            g[i] = g[i * 2] * g[i * 2 + 1];
            return;
        };
        init_poly_eval(1, 0, m - 1);
        poly res(m);
        std::function<void(int, int, int, const poly &)> solve_poly_eval = [&](int i, int l, int r, const poly &f)
        {
            if (l == r)
            {
                res[l] = f[0];
                return;
            }

            int mid = (l + r) / 2;
            solve_poly_eval(i * 2, l, mid, f % g[i * 2]);
            solve_poly_eval(i * 2 + 1, mid + 1, r, f % g[i * 2 + 1]);
            return;
        };
        solve_poly_eval(1, 0, m - 1, f);
        return res;
    }
    struct Point
    {
        int x, y;
    };
    poly poly_inte(const std::vector<Point> &p)
    {
        int n = p.size() - 1;
        std::vector<poly> g(n << 2);
        std::function<void(int, int, int)> init_poly_eval = [&](int i, int l, int r)
        {
            if (l == r)
            {
                g[i] = (poly){
                    MOD - p[l].x, 1};
                return;
            }

            int mid = (l + r) / 2;
            init_poly_eval(i * 2, l, mid);
            init_poly_eval(i * 2 + 1, mid + 1, r);
            g[i] = g[i * 2] * g[i * 2 + 1];
            return;
        };
        init_poly_eval(1, 0, n);
        poly x(n + 1);

        for (int i = 0; i <= n; i++)
            x[i] = p[i].x;

        poly F = poly_eval(diff_calc(g[1]), x);
        std::vector<int> a(n + 1);

        for (int i = 0; i <= n; i++)
            a[i] = 1LL * p[i].y * getinv(F[i]) % MOD;

        std::vector<poly> res(n << 2);
        std::function<void(int, int, int)> solve_poly_inte = [&](int i, int l, int r)
        {
            if (l == r)
            {
                res[i] = {a[l]};
                return;
            }

            int mid = (l + r) / 2;
            solve_poly_inte(i * 2, l, mid);
            solve_poly_inte(i * 2 + 1, mid + 1, r);
            res[i] = res[i * 2] * g[i * 2 + 1] + res[i * 2 + 1] * g[i * 2];
            return;
        };
        solve_poly_inte(1, 0, n);
        return res[1];
    }
    poly operator|(const poly &F, const poly &G)
    {
        poly f = F, g = G;
        int m = std::max(f.size() - 1, g.size() - 1), n = 1;

        while (n <= m)
            n <<= 1;

        f.resize(n), g.resize(n);
        std::function<void(poly &)> fwt = [=](poly &F)
        {
            int n = F.size();

            for (int len = 2; len <= n; len <<= 1)
                for (int i = 0; i < n; i += len)
                    for (int k = i; k < i + len / 2; k++)
                        F[k + len / 2] = (F[k + len / 2] + F[k]) % MOD;

            return;
        };
        fwt(f);
        fwt(g);

        for (int i = 0; i < n; i++)
            f[i] = 1LL * f[i] * g[i] % MOD;

        std::function<void(poly &)> ifwt = [=](poly &F)
        {
            int n = F.size();

            for (int len = 2; len <= n; len <<= 1)
                for (int i = 0; i < n; i += len)
                    for (int k = i; k < i + len / 2; k++)
                        F[k + len / 2] = (F[k + len / 2] - F[k] + MOD) % MOD;

            return;
        };
        ifwt(f);
        return f;
    }
    poly operator&(const poly &F, const poly &G)
    {
        poly f = F, g = G;
        int m = std::max(f.size() - 1, g.size() - 1), n = 1;

        while (n <= m)
            n <<= 1;

        f.resize(n), g.resize(n);
        std::function<void(poly &)> fwt = [=](poly &F)
        {
            int n = F.size();

            for (int len = 2; len <= n; len <<= 1)
                for (int i = 0; i < n; i += len)
                    for (int k = i; k < i + len / 2; k++)
                        F[k] = (F[k] + F[k + len / 2]) % MOD;

            return;
        };
        fwt(f);
        fwt(g);

        for (int i = 0; i < n; i++)
            f[i] = 1LL * f[i] * g[i] % MOD;

        std::function<void(poly &)> ifwt = [=](poly &F)
        {
            int n = F.size();

            for (int len = 2; len <= n; len <<= 1)
                for (int i = 0; i < n; i += len)
                    for (int k = i; k < i + len / 2; k++)
                        F[k] = (F[k] - F[k + len / 2] + MOD) % MOD;

            return;
        };
        ifwt(f);
        return f;
    }
    poly operator^(const poly &F, const poly &G)
    {
        poly f = F, g = G;
        int m = std::max(f.size() - 1, g.size() - 1), n = 1;

        while (n <= m)
            n <<= 1;

        f.resize(n), g.resize(n);
        std::function<void(poly &)> fwt = [=](poly &F)
        {
            int n = F.size();

            for (int len = 2; len <= n; len <<= 1)
                for (int i = 0; i < n; i += len)
                    for (int k = i; k < i + len / 2; k++)
                    {
                        int l = F[k], r = F[k + len / 2];
                        F[k] = (l + r) % MOD;
                        F[k + len / 2] = (l - r + MOD) % MOD;
                    }

            return;
        };
        fwt(f);
        fwt(g);

        for (int i = 0; i < n; i++)
            f[i] = 1LL * f[i] * g[i] % MOD;

        std::function<void(poly &)> ifwt = [=](poly &F)
        {
            int n = F.size();

            for (int len = 2; len <= n; len <<= 1)
                for (int i = 0; i < n; i += len)
                    for (int k = i; k < i + len / 2; k++)
                    {
                        int l = F[k], r = F[k + len / 2];
                        F[k] = (l + r) % MOD;
                        F[k + len / 2] = (l - r + MOD) % MOD;
                    }

            int invn = getinv(n);

            for (int i = 0; i < n; i++)
                F[i] = 1LL * F[i] * invn % MOD;

            return;
        };
        ifwt(f);
        return f;
    }
}
using poly_define::init_poly;
using poly_define::poly;
using poly_define::operator+;
using poly_define::operator-;
using poly_define::operator*;
using poly_define::operator/;
using poly_define::operator%;
using poly_define::operator^;
using poly_define::operator|;
using poly_define::diff_calc;
using poly_define::exp;
using poly_define::getinv;
using poly_define::inte_calc;
using poly_define::ln;
using poly_define::poly_calc;
using poly_define::poly_eval;
using poly_define::poly_inte;
using poly_define::pow;
using poly_define::sqrt;
using namespace std;
int main()
{
    init_poly(1000000);
    int n, m;
    scanf("%d%d", &n, &m);
    poly f, g;
    f.resize(n + 1), g.resize(m + 1);
    for (int i = 0; i <= n; i++)
        scanf("%d", &f[i]);
    for (int i = 0; i <= m; i++)
        scanf("%d", &g[i]);
    poly res = f * g;
    for (int u : res)
        printf("%d ", u);
    return 0;
}