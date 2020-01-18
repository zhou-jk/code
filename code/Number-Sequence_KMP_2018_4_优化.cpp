// VOJ HDU 1711
#include <cctype>
#include <cstdio>

const int N = 1000000, M = 10000, BufferSize = 1 << 16;
int s[N], t[M], n, m, f[M];
char buffer[BufferSize], *head, *tail;

inline char get_char() {
    if (head == tail) {
        int l = fread(buffer, 1, BufferSize, stdin);
        tail = (head = buffer) + l;
    }
    return *head++;
}

inline int read() {
    int x = 0, w = 0;
    char ch = get_char();
    while (!isdigit(ch)) w |= ch == '-', ch = get_char();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = get_char();
    return w ? -x : x;
}

void make_next()  // O(n)
{
    f[0] = f[1] = 0;
    int j = 0;
    for (int i = 1; i < n - 1; i++)  // n就是模式串t的长度
    {
        while (j && t[i] != t[j]) j = f[j];
        f[i + 1] = t[i] == t[j] ? ++j : 0;
    }
}

int match()  // s里面寻找t  O(m)
{
    int j = 0;
    for (int i = 0; i < m; i++)  // 母串s的长度
    {
        while (j && s[i] != t[j]) j = f[j];
        if (s[i] == t[j]) {
            j++;
            if (j == n) return i - n + 2;
        }
    }
    return -1;
}

int main() {
    int cas = read();
    while (cas--) {
        m = read();
        n = read();
        for (int i = 0; i < m; i++) s[i] = read();
        for (int i = 0; i < n; i++) t[i] = read();
        make_next();
        printf("%d\n", match());
    }
    return 0;
}