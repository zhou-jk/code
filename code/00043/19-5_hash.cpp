#include <algorithm>
#include <cstdio>
#include <utility>

using std::pair;
using std::sort;
using std::unique;

const int N = 10000, LEN = 1500, BASE1 = 13, BASE2 = 107, P = 998244353;
char s[LEN + 1];
pair<int, int> a[N];

pair<int, int> hash(const char s[]) {
    pair<int, int> ret;
    ret.first = ret.second = 0;
    for (int i = 0; s[i]; ++i) {
        ret.first = ((long long)ret.first * BASE1 + s[i]) % P;
        ret.second = ((long long)ret.second * BASE2 + s[i]) % P;
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        a[i] = hash(s);
    }
    sort(a, a + n);
    int m = unique(a, a + n) - a;
    printf("%d", m);
    return 0;
}