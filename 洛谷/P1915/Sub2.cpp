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
} res[maxN]; bool eaten[maxN];
complex <double> p[maxN], v[maxN];
double w[maxN], V, deltaw, T;
int ord[maxN], n, cnt;

inline bool cmp(const int &a, const int &b)
{return w[a] < w[b];}

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

int main()
{
    freopen("nemo3.in", "r", stdin);
    freopen("nemo3.out", "w", stdout);
    scanf("%lf%lf%lf%lf%lf%d", w + 0, &V, &T, &p[0].real(), &p[0].imag(), &n);
    for (int i = 1; i < n + 1; ord[i] = i, ++i)
        scanf("%lf%lf%lf%lf%lf", w + i, &p[i].real(), &p[i].imag(), &v[i].real(), &v[i].imag());
    sort(ord + 1, ord + n + 1, cmp);
    for (double t = 0; T - t > zero;)
    {
        static int i = 0; ++i; if (i > n) break;
        double Min = solve(p[ord[i]] + t * v[ord[i]], v[ord[i]], p[0]);
        int pos = ord[i];
        if (fabs(Min - INF) < zero) break;
        if (T - (t += Min) < -zero) break;
        w[0] += w[pos]; deltaw += w[pos]; eaten[pos] = 1;
        res[cnt++] = Res(t, p[0] = p[pos] + t * v[pos], pos);
    }
    printf("%d\n%.9lf\n", cnt, deltaw);
    for (int i = 0; i < cnt; ++i)
        printf("%.9lf %.9lf %.9lf %d\n", res[i].t, res[i].p.real(), res[i].p.imag(), res[i].ord);
    return 0;
}
