#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <complex>
#include <ctime>
#include <cmath>

using namespace std;

const int maxN = 10010;
const double zero = 1e-12, INF = 1e18;
struct Res
{
    double t; complex <double> p; int ord; Res() {}
    Res(double t, complex <double> p, int ord):
        t(t), p(p), ord(ord) {}
} res[maxN], _res[maxN]; bool eaten[maxN];
complex <double> p[maxN], v[maxN];
double w[maxN], V, _deltaw, deltaw, T, tem;
vector <pair <double, int> > ls;
vector <pair <double, int> >::iterator iter;
int ord[maxN], n, cnt, _cnt;

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
} //计算出从O出发，追赶一个当前位置为p，以速度v移动的小虾所需时间。

inline double _rand() {return (double)rand() / RAND_MAX;}

inline bool judge()
{
    if (++iter == ls.end()) {--iter; return 0;}
    if (rand() & 1) {--iter; return 0;}
    //先以0.5的概率初步淘汰较差的解。
    double nxt = iter -> first;
    --iter; double ths = iter -> first;
    double delta = (ths - nxt);
    if (delta / ths < 3.40e-2) return 1;
    //若较差的解比当前解差3.4%以上，直接淘汰。
    return _rand() < 1 / exp(delta / tem);
    //否则以概率e ^ (-delta / tem)的概率接受更差的解。
}

int main()
{
    freopen("nemo4.in", "r", stdin);
    freopen("nemo4.out", "w", stdout);
    srand(time(NULL));
    scanf("%lf%lf%lf%lf%lf%d", w + 0, &V, &T, &p[0].real(), &p[0].imag(), &n);
    complex <double> p0 = p[0]; double w0 = w[0];
    for (int i = 1; i < n + 1; ord[i] = i, ++i)
        scanf("%lf%lf%lf%lf%lf", w + i, &p[i].real(), &p[i].imag(), &v[i].real(), &v[i].imag());
    sort(ord + 1, ord + n + 1, cmp); //将小虾按体重从小到大的顺序排序。
    tem = 1; //初始温度设为1。
    for (int k = 0; k < 15; ++k)
    {
        memset(eaten, 0, sizeof eaten);
        _deltaw = 0; _cnt = 0; p[0] = p0; w[0] = w0;
        for (double t = 0; t < T;)
        {
            ls.clear();
            for (int i = 1; w[ord[i]] < w[0]; ++i)
            if (!eaten[ord[i]])
                ls.push_back(make_pair(w[ord[i]] / sqr(solve(p[ord[i]] + t * v[ord[i]], v[ord[i]], p[0])), ord[i]));
            sort(ls.begin(), ls.end(), greater <pair <double, int> > ());
            iter = ls.begin(); if (iter == ls.end()) break;
            while (judge()) ++iter;
            int pos = iter -> second;
            if (T - (t += solve(p[pos] + t * v[pos], v[pos], p[0])) < -zero) break;
            _deltaw += w[pos], w[0] += w[pos]; eaten[pos] = 1;
            _res[_cnt++] = Res(t, p[0] = p[pos] + t * v[pos], pos);
        }
        if (_deltaw > deltaw)
        {
            deltaw = _deltaw;
            for (cnt = 0; cnt < _cnt; ++cnt) res[cnt] = _res[cnt];
        } //更新最优解。
        tem *= .5;
    }
    printf("%d\n%.9lf\n", cnt, deltaw);
    for (int i = 0; i < cnt; ++i)
        printf("%.9lf %.9lf %.9lf %d\n", res[i].t, res[i].p.real(), res[i].p.imag(), res[i].ord);
    return 0;
}
