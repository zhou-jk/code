// AC
#include <algorithm>
#include <cstdio>

using std::min;

const int N = 1120, K = 14;
long long f[K + 1][N + 1];
int prime[(N + 1) >> 1], cnt;
bool bPrime[N + 1];

int main() {
    int n, k;
    for (int i = 2; i <= N; ++i) {
        if (!bPrime[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt && prime[j] * i <= N; ++j) {
            bPrime[prime[j] * i] = true;
            if (!(i % prime[j])) break;
        }
    }
    f[0][0] = 1;
    for (int i = 0; i < cnt; ++i)
        for (int j = K; j; --j)
            for (int p = N; p >= prime[i]; --p)
                f[j][p] += f[j - 1][p - prime[i]];
    while (scanf("%d%d", &n, &k) != EOF && n && k) printf("%lld\n", f[k][n]);
    return 0;
}
