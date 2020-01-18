// AC
#include <cstdio>

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d", n % (k + 1) ? 1 : 2);
    return 0;
}