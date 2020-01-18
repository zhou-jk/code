// AC
#include <cstdio>

bool vis[10];

int f(int num) {
    int ret = num + 1;
    while (!(ret % 10)) ret /= 10;
    return ret;
}

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    int i = n;
    while (i > 9 || !vis[i]) {
        if (i < 10) vis[i] = true;
        ++ans;
        i = f(i);
    }
    printf("%d", ans);
    return 0;
}