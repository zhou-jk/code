//AC
#include <cstdio>

int main() {
    int n, cnt1 = 0, cnt2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp == 1)
            ++cnt1;
        else
            ++cnt2;
    }
    if (cnt1 && cnt2) {
        printf("%d %d ", 2, 1);
        --cnt1;
        --cnt2;
    }
    while (cnt2--) printf("%d ", 2);
    while (cnt1--) printf("%d ", 1);
    return 0;
}