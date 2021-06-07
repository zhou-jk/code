#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    int n;
    long long m;
    scanf("%d %lld", &n, &m);
    std::vector<int>a(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a.begin(), a.end(), std::greater<int>());
    std::function<bool(int)>check = [ = ](int x) {
        long long cnt = 0;

        for (int i = 0, j = n - 1; i < n; i++) {
            while (j >= 0 && a[i] + a[j] < x)
                j--;

            cnt += j + 1;
        }

        return cnt >= m;
    };
    int l = a[n - 1] + a[n - 1], r = a[0] + a[0], v = -1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (check(mid))
            v = mid, l = mid + 1;
        else
            r = mid - 1;
    }

    std::vector<long long>sum(n);
    sum[0] = a[0];

    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + a[i];

    long long cnt = 0, ans = 0;

    for (int i = 0, j = n - 1; i < n; i++) {
        while (j >= 0 && a[i] + a[j] < v)
            j--;

        if (j >= 0)
            cnt += j + 1, ans += (long long)a[i] * (j + 1) + sum[j];
    }

    ans -= (cnt - m) * v;
    printf("%lld", ans);
    return 0;
}