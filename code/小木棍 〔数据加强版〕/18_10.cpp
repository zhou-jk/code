#include <cstdio>
#include <algorithm>

using std::max;
using std::min;

const int N = 65, MAX = 50;
int a[MAX + 1], sum, min_ = 10000, max_;

void dfs(int s, int sum, int b, int k)
{
    if (!s)
    {
        printf("%d", b);
        exit(0);
    }
    if (sum == b)
        dfs(s - 1, 0, b, max_);
    else
        for (int i = k; i >= min_; --i)
            if (a[i] && sum + i <= b)
            {
                --a[i];
                dfs(s, sum + i, b, i);
                ++a[i];
                if (!sum || sum + i == b)
                    break;
            }
    return;
}

int main()
{
    int n, num;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &num);
        if (num <= 50)
        {
            sum += num;
            min_ = min(min_, num);
            max_ = max(max_, num);
            ++a[num];
        }
    }
    int tmp = sum >> 1;
    for (int i = max_; i <= tmp; ++i)
        if (!(sum % i))
            dfs(sum / i, 0, i, max_);
    printf("%d", sum);
    return 0;
}