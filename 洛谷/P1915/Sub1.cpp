#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>

using namespace std;

const int maxN = 10010;
const double zero = 1e-12, INF = 1e198;
struct Res
{
    double t; complex <double> p; int ord; Res() {}
    Res(double t, complex <double> p, int ord):
        t(t), p(p), ord(ord) {}
} res[maxN], tmp[maxN]; bool eaten[maxN];
complex <double> p[maxN], v[maxN];
double w[maxN], V, deltaw, T;
int n, cnt;

inline double sqr(double x) {return x * x;}

inline double sqr(complex <double> z)
{return sqr(real(z)) + sqr(imag(z));}

inline double solve(complex <double> p,
                    complex <double> v,
                    complex <double> O)
{
    double a = sqr(v) - sqr(V),
    b = -2 * (real(v) * real(O - p) + imag(v) * imag(O - p)),
    c = sqr(p - O),
    delta = sqr(b) - 4 * a * c;
    if (delta < -zero) return INF;
    if (fabs(a) < zero)
        return (b > -zero) ? INF : (-c / b);
    double ans = INF,
           x1 = (-b - sqrt(delta)) / (2 * a),
           x2 = (-b + sqrt(delta)) / (2 * a);
    if (x1 > -zero) ans = x1;
    if (x2 > -zero && x2 < ans) ans = x2;
    return ans;
}

void Dfs(int i, double w0, double t, complex <double> p0)
{
    for (int j = 1; j < n + 1; ++j)
    if (!eaten[j] && w[j] < w0)
    {
        double ths = solve(p[j] + t * v[j], v[j], p0);
        if (t + ths - T > zero) continue;
        complex <double> pos = p[j] + (t + ths) * v[j];
        eaten[j] = 1;
        tmp[i] = Res(t + ths, pos, j);
        Dfs(i + 1, w0 + w[j], t + ths, pos);
        tmp[i] = Res(0, 0, 0);
        eaten[j] = 0;
    }
    if (w0 - w[0] > deltaw)
    {
        deltaw = w0 - w[0];
        for (cnt = 0; tmp[cnt].t > zero; ++cnt)
            res[cnt] = tmp[cnt];
    }
    return;
}
int main()
{
    freopen("nemo1.in", "r", stdin);
    freopen("nemo1.out", "w", stdout);
    scanf("%lf%lf%lf%lf%lf%d", w + 0, &V, &T, &p[0].real(), &p[0].imag(), &n);
    for (int i = 1; i < n + 1; ++i)
        scanf("%lf%lf%lf%lf%lf", w + i, &p[i].real(), &p[i].imag(), &v[i].real(), &v[i].imag());
    Dfs(0, w[0], 0, p[0]);
    printf("%d\n%.9lf\n", cnt, deltaw);
    for (int i = 0; i < cnt; ++i)
        printf("%.9lf %.9lf %.9lf %d\n", res[i].t, res[i].p.real(), res[i].p.imag(), res[i].ord);
    return 0;
}
