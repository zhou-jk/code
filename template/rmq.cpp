#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
template<typename T>
struct RMQ
{
    const int N = 100005;
    const int K = 19, Mx = 29;
    int a[N], lp[N], rp[N], bel[N];
    int prefix[N], suffix[N], ST[N][K];
    int state[N];
    void init(const vector<T> &val)
    {
        int B = __lg(n) / 2 * 3;
        for (int i = 1; i <= n; ++i)
            bel[i] = (i - 1) / B + 1;
        for (int i = 1; i <= bel[n]; i++)
        {
            lp[i] = (i - 1) * B + 1;
            rp[i] = min(i * B, n);
        }
        for (int i = 1; i <= bel[n]; i++)
        {
            int mx = 0;
            for (int j = lp[i]; j <= rp[i]; j++)
                prefix[j] = (mx = max(mx, a[j]));
            mx = 0;
            for (int j = rp[i]; j >= lp[i]; --j)
                suffix[j] = (mx = max(mx, a[j]));
            ST[i][0] = mx;
        }
        for (int j = 1; (1 << j) <= bel[n]; ++j)
            for (int i = 1; i + (1 << j) - 1 <= bel[n]; ++i)
                ST[i][j] = max(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
        for (int i = 1; i <= bel[n]; ++i)
        {
            stack<int> stk;
            int cur = 0;
            for (int j = lp[i]; j <= rp[i]; ++j)
            {
                while (!stk.empty() && a[j] >= a[stk.top()])
                {
                    cur -= 1 << (stk.top() - lp[i]);
                    stk.pop();
                }
                stk.emplace(j);
                cur += 1 << (j - lp[i]);
                state[j] = cur;
            }
        }
    }
    int ST_query(int l, int r)
    {
        int k = __lg(r - l + 1);
        return max(ST[l][k], ST[r - (1 << k) + 1][k]);
    }
    int query(int l, int r)
    {
        if (bel[l] == bel[r])
            return a[l + __builtin_ctz(state[r] >> (l - lp[bel[l]]))];
        if (bel[l] + 1 <= bel[r] - 1)
            return max(ST_query(bel[l] + 1, bel[r] - 1), max(suffix[l], prefix[r]));
        return max(suffix[l], prefix[r]);
    }
}rmq;
int n, q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init(n);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << "\n";
    }
    return 0;
}