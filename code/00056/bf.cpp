// AC
#include <cmath>
#include <cstdio>

const double PI = 3.14159;

int main() {
    freopen("bf.in", "r", stdin);
    freopen("bf.out", "w", stdout);
    int n;
    while (scanf("%d", &n) != EOF && n) printf("%.2f\n", n * n / PI / 2);
    return 0;
}
