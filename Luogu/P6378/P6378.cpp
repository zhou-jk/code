#include<iostream>
#include<cstdio>
#include<stack>
#include<array>
#include<vector>
using namespace std;
const int N=1000005;
int n,m,k;
int a[N][2],cnt;
vector<array<int,2>>b[N];
vector<int>G[N*4];
int dfn[N*4],low[N*4],Index;
int bel[N*4],tot;
void tarjan(int u)
{
    static bool vis[N*4];
    static stack<int> s;
    dfn[u]=low[u]=++Index;
    s.emplace(u);
    vis[u]=true;
    for(int v:G[u])
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]) low[u]=min(low[u],dfn[v]);
    if(dfn[u]==low[u])
    {
        tot++;
        while(s.top()!=u)
        {
            bel[s.top()]=tot;
            vis[s.top()]=false;
            s.pop();
        }
        bel[u]=tot;
        vis[u]=false;
        s.pop();
    }
    return;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        a[i][0]=++cnt,a[i][1]=++cnt;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[a[x][0]].emplace_back(a[y][1]);
        G[a[y][0]].emplace_back(a[x][1]);
    }
    for(int t=1;t<=k;t++)
    {
        int w;
        scanf("%d",&w);
        b[t].resize(w);
        for(int i=0;i<w;i++)
            b[t][i][0]=++cnt,b[t][i][1]=++cnt;
        for(int i=0;i<w;i++)
        {
            int x;
            scanf("%d",&x);
            G[a[x][1]].emplace_back(b[t][i][1]);
            G[b[t][i][0]].emplace_back(a[x][0]);
            if(i>0)
            {
                G[b[t][i-1][1]].emplace_back(b[t][i][1]);
                G[b[t][i][0]].emplace_back(b[t][i-1][0]);
                G[b[t][i-1][1]].emplace_back(a[x][0]);
                G[a[x][1]].emplace_back(b[t][i-1][0]);
            }
        }
    }
    for(int i=1;i<=cnt;i++)
        if(!dfn[i]) tarjan(i);
    for(int i=1;i<=n;i++)
        if(bel[a[i][0]]==bel[a[i][1]])
        {
            printf("NIE");
            return 0;
        }
    for(int t=1;t<=k;t++)
        for(int i=0;i<(int)b[t].size();i++)
            if(bel[b[t][i][0]]==bel[b[t][i][1]])
            {
                printf("NIE");
                return 0;
            }
    printf("TAK");
    return 0;
}