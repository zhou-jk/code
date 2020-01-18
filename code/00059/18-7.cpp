// AC
#include <cstdio>

const int NUM = 60;
int sg[NUM + 1];

inline char get_ch() {
    static const int SIZE = 1 << 15;
    static char buf[SIZE], *l = NULL, *r = NULL;
    return l == r && (r = (l = buf) + fread(buf, 1, SIZE, stdin), l == r)
               ? EOF
               : *l++;
}

//#define get_ch getchar

inline int get_int() {
    int ret = 0;
    bool flag = false;
    char ch = get_ch();
    for (; ch < '0' || ch > '9'; ch = get_ch()) flag |= ch == '-';
    for (; ch >= '0' && ch <= '9'; ch = get_ch())
        ret = (ret << 3) + (ret << 1) + (ch ^ 48);
    return flag ? -ret : ret;
}

int main() {
    for (int i = 1; i <= NUM; ++i) {
        int tmp = i, j;
        for (j = 1; j <= tmp; ++j) tmp -= j;
        sg[i] = j - 1;
    }
    int n = get_int(), ans = 0;
    for (int i = 0; i < n; ++i) ans ^= sg[get_int()];
    if (ans)
        puts("NO");
    else
        puts("YES");
    return 0;
}