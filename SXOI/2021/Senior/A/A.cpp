#include <cstdio>
#include <vector>
#include <functional>

int main() {
    int n, x;
    scanf("%d %d", &n, &x);

    std::function<int(int)>calc = [ = ](int n) {
        int ret = n;
        int cnt = 0;

        while (ret > 0) {
            if (ret % 10 == x)
                cnt++;

            ret /= 10;
        }

        return cnt;
    };

    int ans = 0;

    for (int i = 1; i <= n; i++)
        ans += calc(i);

    printf("%d", ans);

    return 0;
}
