#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>

using std::isdigit;
using std::printf;
using std::putchar;
using std::scanf;
using std::sort;
using std::sqrt;

struct Query {
    int l, r, id;
};

const int N = 500000, Q = 500000, KIND = 1000000;
int a[N], belong[N], ans[Q], cnt[KIND], now;
Query query[Q];

inline char GetChar() {
    static const int SIZE = 1 << 20;
    static char buf[SIZE], *s, *t;
    return s == t && (t = (s = buf) + fread(buf, 1, SIZE, stdin), s == t)
               ? EOF
               : *s++;
}

#define getchar GetChar

inline int GetInt() {
    char c;
    int ret = 0;
    bool p = false;
    for (c = getchar(); !isdigit(c); c = getchar()) p |= c == '-';
    for (; isdigit(c); c = getchar()) ret = (ret << 1) + (ret << 3) + (c ^ 48);
    return p ? -ret : ret;
}

inline void put_int(int num) {
    if (num > 9) put_int(num / 10);
    putchar((num % 10) ^ 48);
}

inline bool cmp(const Query &a, const Query &b) {
    return belong[a.l] != belong[b.l]
               ? belong[a.l] < belong[b.l]
               : (belong[a.l] & 1 ? a.r < b.r : b.r < a.r);
}

inline void Add(int k) {
    // printf("#%d\n", k);
    if (!cnt[a[k]]) ++now;
    ++cnt[a[k]];
}

inline void Del(int k) {
    // printf("$%d\n", k);
    --cnt[a[k]];
    if (!cnt[a[k]]) --now;
}

int main() {
    int n, q;
    n = GetInt();
    for (int i = 0; i < n; ++i) a[i] = GetInt();
    q = GetInt();
    for (int i = 0; i < q; ++i) {
        query[i].l = GetInt() - 1;
        query[i].r = GetInt() - 1;
        query[i].id = i;
    }
    int size = n / sqrt(q * 2 / 3);
    for (int i = 0; i < n; ++i) belong[i] = i / size;
    sort(query, query + q, cmp);
    int l = 0, r = -1;
    for (int i = 0; i < q; ++i) {
        while (query[i].l < l) Add(--l);
        while (query[i].l > l) Del(l++);
        while (query[i].r > r) Add(++r);
        while (query[i].r < r) Del(r--);
        ans[query[i].id] = now;
    }
    for (int i = 0; i < q; ++i) {
        put_int(ans[i]);
        putchar('\n');
    }
    return 0;
}