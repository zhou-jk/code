#include <cstdio>
#include <vector>

using std::vector;

const int N = 1000;
vector<int> g[N];
bool vis[N];

void dfs(int k)
{
    vis[k] = true;
    for (int i = 0; i < g[k].size(); ++i)
        if (!vis[g[k][i]])
            dfs(g[k][i]);
}

int main()
{
    //puts("a");
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    for (int i = 0; i < n; ++i)
        if (!vis[i] || g[i].size() & 1)
        {
            puts("0");
            return 0;
        }
    puts("1");
    return 0;
}