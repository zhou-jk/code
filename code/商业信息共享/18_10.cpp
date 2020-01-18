#include <cstdio>
#include <algorithm>

using std::max;
using std::min;

const int N = 100;
int edge[N][N];
int belong[N], cnt_scc;
bool ind[N], outd[N];

int dfn[N], low[N], cnt_dfs;
int stk[N], top;
bool in_stk[N];
void tarjan(int k)
{
    dfn[k] = low[k] = ++cnt_dfs;
    stk[top++] = k;
    in_stk[k] = true;
    for (int i = 1; i <= edge[k][0]; ++i)
    {
        int v = edge[k][i];
        if (!dfn[v])
        {
            tarjan(v);
            low[k] = min(low[k], low[v]);
        }
        else if (in_stk[v])
            low[k] = min(low[k], dfn[v]);
    }
    if (dfn[k] == low[k])
    {
        do
        {
            belong[stk[--top]] = cnt_scc;
            in_stk[stk[top]] = false;
        } while (stk[top] != k);
        ++cnt_scc;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int v;
        while (scanf("%d", &v) != EOF && v)
            edge[i][++edge[i][0]] = v - 1;
    }
    for (int i = 0; i < n; ++i)
        if (!dfn[i])
            tarjan(i);
    for (int i = 0; i < n; ++i)
    {
        outd[belong[i]] = (bool)edge[i][0];
        for (int j = 1; j <= edge[i][0]; ++j)
        {
            int v = edge[i][j];
            if (belong[i] != belong[v])
                ind[belong[v]] = true;
        }
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < cnt_scc; ++i)
    {
        if (!ind[i])
            ++ans1;
        if (!outd[i])
            ++ans2;
    }
    printf("%d\n%d", ans1, cnt_scc == 1 ? 0 : max(ans1, ans2));
    return 0;
}