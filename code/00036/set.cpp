// AC
#include <algorithm>
#include <cstdio>
#include <cstring>

using std::sort;

const int N = 500, N_PRIME = 8, M = 1 << N_PRIME,
          prime[N_PRIME] = {2, 3, 5, 7, 11, 13, 17, 19};
struct Num {
    int num, bigPrime, primeSet;
    Num(int _num = 0) : num(_num) {
        primeSet = 0;
        if (_num)
            for (int i = 0; i < N_PRIME; ++i)
                if (!(_num % prime[i])) {
                    primeSet |= 1 << i;
                    while (!(_num % prime[i])) _num /= prime[i];
                }
        bigPrime = _num;
    }
} num[N + 1];
long long f[M][M], f1[M][M], f2[M][M], p;

bool Cmp(const Num &a, const Num &b) { return a.bigPrime < b.bigPrime; }

inline long long Add(long long a, long long b) {
    long long ret = a + b;
    return ret < p ? ret : ret - p;
}

int main() {
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    int n;
    scanf("%d%lld", &n, &p);
    for (int i = 2; i <= n; ++i) num[i - 1] = Num(i);
    sort(num + 1, num + n, Cmp);
    f[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        if (num[i].bigPrime == 1 || num[i].bigPrime != num[i - 1].bigPrime) {
            memcpy(f1, f, sizeof f);
            memcpy(f2, f, sizeof f);
        }
        for (int j = M - 1; ~j; --j)
            for (int k = M - 1; ~k; --k)
                if (!(j & k)) {
                    if (!(num[i].primeSet & k))
                        f1[j | num[i].primeSet][k] =
                            Add(f1[j | num[i].primeSet][k], f1[j][k]);
                    if (!(num[i].primeSet & j))
                        f2[j][k | num[i].primeSet] =
                            Add(f2[j][k | num[i].primeSet], f2[j][k]);
                }
        if (num[i].bigPrime == 1 || num[i].bigPrime != num[i + 1].bigPrime)
            for (int j = 0; j < M; ++j)
                for (int k = 0; k < M; ++k)
                    if (!(j & k))
                        f[j][k] = Add(f1[j][k], Add(f2[j][k], p - f[j][k]));
    }
    long long ans = 0;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < M; ++j)
            if (!(i & j)) ans = Add(ans, f[i][j]);
    printf("%lld", ans);
    return 0;
}
