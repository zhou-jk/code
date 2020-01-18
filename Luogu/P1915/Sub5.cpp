#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>

using namespace std;

const int maxN = 2010, INF = 0x3f3f3f3f;
const double zero = 1e-12;
struct Res
{
    double t; complex <int> p; int ord; Res() {}
    Res(double t, complex <int> p, int ord):
        t(t), p(p), ord(ord) {}
} res[maxN], tmp[maxN]; bool eaten[maxN];
complex <int> p[maxN], v[maxN];
double w[maxN], deltaw, V, T, f[maxN][maxN];
int ord[maxN][maxN], g[maxN], n, cnt;

inline double sqr(double x) {return x * x;}

inline double sqr(complex <double> z)
{return sqr(real(z)) + sqr(imag(z));}

int main()
{
    freopen("nemo8.in", "r", stdin);
    freopen("nemo8.out", "w", stdout);
    scanf("%lf%lf%lf%d%d%d", w + 0, &V, &T, &p[0].real(), &p[0].imag(), &n);
    for (int i = 1; i < n + 1; ++i)
        scanf("%lf%d%d%d%d", w + i, &p[i].real(), &p[i].imag(), &v[i].real(), &v[i].imag());
    for (int i = 1; i < n + 1; ++i)
        ord[real(p[i])][imag(p[i])] = i;
    int i = n;
    for (; i; --i)
    {
        f[real(p[i])][imag(p[i])] = w[i];
        if (imag(p[i - 1]) < imag(p[i])) break;
    }
    while (--i)
    {
        int x = real(p[i]), y = imag(p[i]), ths = ord[x][y];
        if (f[x - 1][y + 1] > f[x + 1][y + 1])
        {
            f[x][y] = w[i] + f[x - 1][y + 1];
            g[ths] = ord[x - 1][y + 1];
        }
        else
        {
            f[x][y] = w[i] + f[x + 1][y + 1];
            g[ths] = ord[x + 1][y + 1];
        }
    }
    double t = 0;
    res[cnt++] = Res(t = abs(p[1] - p[0]) / V, p[1], 1);
    for (int ths = 1; g[ths]; ths = g[ths])
        res[cnt++] = Res(t += abs(complex <double> (real(p[g[ths]] - p[ths]), imag(p[g[ths]] - p[ths]))) / V, p[g[ths]], g[ths]);
    for (int i = 0; i < cnt; ++i) deltaw += w[res[i].ord];
    printf("%d\n%lf\n", cnt, deltaw);
    for (int i = 0; i < cnt; ++i)
        printf("%.9lf %d %d %d\n", res[i].t, res[i].p.real(), res[i].p.imag(), res[i].ord);
    return 0;
}
