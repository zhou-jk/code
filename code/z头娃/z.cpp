// AC
#pragma GCC optimize(2)
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>

using std::sort;

typedef long long ll;
int ss[100000], p, nn;

inline char get_char() {
    static const int SIZE = 2 << 16;
    static char buf[SIZE], *s, *t;
    if (s == t) {
        t = (s = buf) + fread(buf, 1, SIZE, stdin);
        if (s == t) return EOF;
    }
    return *s++;
}

#define getchar get_char

inline int get_int() {
    char c;
    int ret = 0;
    for (c = getchar(); !isdigit(c); c = getchar())
        ;
    for (; isdigit(c); c = getchar()) ret = (ret << 1) + (ret << 3) + (c ^ 48);
    return ret;
}

inline int get_ll() {
    char c;
    ll ret = 0;
    for (c = getchar(); !isdigit(c); c = getchar())
        ;
    for (; isdigit(c); c = getchar()) ret = (ret << 1) + (ret << 3) + (c ^ 48);
    return ret;
}

int phi(int num) {
    int tmp = sqrt(num), ret = num;
    for (int i = 2; i <= tmp; ++i)
        if (!(num % i)) {
            ret -= ret / i;
            while (!(num % i)) num /= i;
        }
    if (num > 1) ret -= ret / num;
    return ret;
}

void solve(int num) {
    int tmp = sqrt(num);
    for (int i = 1; i <= tmp; ++i)
        if (!(num % i)) {
            ss[nn++] = i;
            if (i * i != num) ss[nn++] = num / i;
        }
    sort(ss, ss + nn);
}

int pow(ll a, int b) {
    a %= p;
    ll ret = 1 % p;
    while (b) {
        if (b & 1) ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}

int main() {
    freopen("z.in", "r", stdin);
    freopen("z.out", "w", stdout);
    int q, s;
    p = get_int();
    q = get_int();
    s = phi(p);
    solve(s);
    while (q--) {
        ll a = get_ll();
        int b = get_int();
        if (pow(a, s) != 1) {
            puts("Wrong!!!");
            continue;
        }
        bool flag = false;
        for (int i = 0; i < nn && ss[i] <= b; ++i)
            if (pow(a, ss[i]) == 1) {
                flag = true;
                break;
            }
        if (flag)
            puts("sxdorz");
        else
            puts("sxddjl");
    }
    return 0;
}