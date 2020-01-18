//AC
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, r, a = 1E9, b = 0;
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp < a) a = tmp;
    }
    for (int i = 0; i < m; ++i) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp > b) b = tmp;
    }
    if (a >= b) {
        printf("%d", r);
        return 0;
    }
    printf("%d", r % a + r / a * b);
    return 0;
}