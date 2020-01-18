#include <cstdio>

using namespace std;

int main() {
    int f[51] = {1, 0, 1}, n;
    scanf("%d", &n);
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 2] + f[i - 3];
    }
    printf("%d\n", f[n]);
    return 0;
}
