#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;

const int N = 10000, M = 50000;
struct Edge
{
    int v, next;
} edge[M];
int head[N], cnt_edge;
int belong[N], cnt_scc;
bool is_ans[N];

void add_edge(int u, int v)
{
    edge[cnt_edge].v = v;
    edge[cnt_edge].next = head[u];
    head[u] = cnt_edge++;
}

int dfn[N], low[N], cnt_dfs;
int stk[N], top;
bool in_stk[N];
void tarjan(int k)
{
    dfn[k] = low[k] = ++cnt_dfs;
    stk[top++] = k;
    in_stk[k] = true;
    for (int i = head[k]; ~i; i = edge[i].next)
    {
        int v = edge[i].v;
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
    int n, m;
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof head);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u - 1, v - 1);
    }
    for (int i = 0; i < n; ++i)
        if (!dfn[i])
            tarjan(i);
    memset(is_ans, true, sizeof is_ans);
    for (int i = 0; i < n; ++i)
    {
        int tmp = belong[i];
        //printf("%d %d\n", i, tmp);
        for (int j = head[i]; ~j; j = edge[j].next)
            if (belong[edge[j].v] != tmp)
                is_ans[tmp] = false;
    }
    int ans_scc = -1;
    for (int i = 0; i < cnt_scc; ++i)
        if (is_ans[i])
        {
            if (!(~ans_scc))
                ans_scc = i;
            else
            {
                puts("0");
                return 0;
            }
        }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (belong[i] == ans_scc)
            ++ans;
    printf("%d", ans);
    return 0;
}