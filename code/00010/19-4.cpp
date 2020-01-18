// AC
#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i < n; ++i)
        if (!(n % i)) {
            printf("%d", n / i);
            return 0;
        }
    return 0;
}