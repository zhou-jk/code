// AC
#include <algorithm>
#include <cstdio>

using std::max;

const int A = 1000, B = 500;
int f[A + 1][B + 1];

int main() {
    int a, b, n, ans1 = 0, ans2 = 0;
    scanf("%d%d%d", &a, &b, &n);
    for (int i = 0; i < n; ++i) {
        int a_, b_;
        scanf("%d%d", &a_, &b_);
        for (int j = a; j >= a_; --j)
            for (int k = b; k >= b_; --k) {
                f[j][k] = max(f[j][k], f[j - a_][k - b_] + 1);
                if (f[j][k] == ans1 ? b - k > ans2 : f[j][k] > ans1) {
                    ans1 = f[j][k];
                    ans2 = b - k;
                }
            }
    }
    printf("%d %d", ans1, ans2);
    return 0;
}