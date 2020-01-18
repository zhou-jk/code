// AC
#include <cstdio>

const int LEN = 200000;
char num[LEN + 1];
int f[10];

int main() {
    int n;
    scanf("%d%s", &n, num);
    for (int i = 1; i < 10; ++i) scanf("%d", f + i);
    bool flag = false;
    for (int i = 0; num[i]; ++i) {
        int tmp = num[i] ^ 48;
        if (f[tmp] > tmp) flag = true;
        if (flag && f[tmp] < tmp) break;
        if (flag) num[i] = f[tmp] ^ 48;
    }
    puts(num);
    return 0;
}