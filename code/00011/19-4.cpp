// AC
#include <algorithm>
#include <cstdio>

using std::max;

const int N = 100000, MAX = 1000000;
int a[N], f[MAX + 1], ss[MAX + 1];
bool vis[MAX + 1];

int main() {
    int n, maxa = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        ++ss[a[i]];
        maxa = max(maxa, a[i]);
    }
    for (int i = 0; i < n; ++i)
        if (!vis[a[i]]) {
            vis[a[i]] = true;
            for (int j = a[i]; j <= maxa; j += a[i]) f[j] += ss[a[i]];
        }
    for (int i = 0; i < n; ++i) printf("%d\n", f[a[i]] - 1);
    return 0;
}