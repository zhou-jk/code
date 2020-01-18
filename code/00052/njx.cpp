// AC
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>

using std::max;

const int N = 5000000;
char num[25];
unsigned long long a[N], res;
int n;
bool flag[N];

inline char GetChar() {
    static const int SIZE = 1 << 20;
    static char buf[SIZE], *s = buf, *t = buf;
    return s == t && (t = (s = buf) + fread(buf, 1, SIZE, stdin), s == t)
               ? EOF
               : *s++;
}

#define getchar GetChar

template <typename T>
inline void GetNum(T &num) {
    num = 0;
    bool w = false;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) w |= ch == '-';
    for (; isdigit(ch); ch = getchar())
        num = (num << 1) + (num << 3) + (ch ^ 48);
    num = w ? -num : num;
}

inline void GetStr(char str[]) {
    memset(str, 0, 25);
    char ch = getchar();
    for (; isspace(ch); ch = getchar())
        ;
    for (int i = 0; !isspace(ch); ch = getchar(), ++i) str[i] = ch;
}

template <typename T>
inline void StrToNum(const char str[], T &num) {
    for (int i = 0; str[i]; ++i) num = (num << 1) + (num << 3) + (str[i] ^ 48);
}

inline unsigned long long solve() {
    unsigned long long ret = 0;
    for (int i = 0; i < n; ++i)
        if (!flag[i]) ret = max(ret, res ^ a[i]);
    return ret;
}

void Add(char ret[], unsigned long long a, const char b[]) {
    memset(ret, 0, 25);
    int t = 0;
    int len = strlen(b);
    for (int i = len - 1; i >= 0 || a || t; --i, a /= 10) {
        ret[len - i - 1] = t + a % 10;
        if (i >= 0) ret[len - i - 1] += b[i] ^ 48;
        t = ret[len - i - 1] / 10;
        ret[len - i - 1] = (ret[len - i - 1] % 10) ^ 48;
    }
}

void output(const char str[]) {
    int len = strlen(str);
    for (int i = len - 1; ~i; --i) putchar(str[i]);
}

int main() {
    freopen("njx.in", "r", stdin);
    freopen("njx.out", "w", stdout);
    unsigned long long ans;
    int cnt = 0;
    GetNum(n);
    for (int i = 0; i < n; ++i) {
        GetStr(num);
        if (!strcmp(num, "18446744073709551616")) {
            flag[i] = true;
            ++cnt;
        } else {
            StrToNum(num, a[i]);
            res ^= a[i];
        }
    }
    if (cnt) {
        if (cnt & 1) {
            if (cnt == n)
                putchar('0');
            else {
                ans = solve();
                Add(num, ans, "18446744073709551616");
                output(num);
            }
        } else {
            Add(num, res, "18446744073709551616");
            output(num);
        }
    } else
        printf("%llu", solve());
    return 0;
}
