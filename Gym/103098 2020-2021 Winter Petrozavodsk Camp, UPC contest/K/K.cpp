#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1000005;
int n,m,k;
int x[N],y[N];
struct Edge
{
    int to,next;
}edge[N<<1];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int dfn[N],low[N],Index;
bool bridge[N+N];
void tarjan(int u,int prev)
{
    dfn[u]=low[u]=++Index;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(!dfn[v])
        {
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]) bridge[i]=bridge[i^1]=true;
        }
        else if(i!=(prev^1)) low[u]=min(low[u],dfn[v]);
    }
    return;
}
int bel[N],tot;
void build(int u)
{
    bel[u]=tot;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(bel[v]||bridge[i]) continue;
        build(v);
    }
    return;
}
vector<int>G[N];
int d1[N],p1[N];
void dfs(int u,int father)
{
    d1[u]=0,p1[u]=u;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
        if(d1[u]<d1[v]+1)
        {
            d1[u]=d1[v]+1;
            p1[u]=p1[v];
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    cnt=1;
    for(int i=1;i<=m;i++)
    {
        cin>>x[i]>>y[i];
        x[i]++,y[i]++;
        add_edge(x[i],y[i]);
        add_edge(y[i],x[i]);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i]) tarjan(i,0);
    for(int i=1;i<=n;i++)
        if(!bel[i])
        {
            tot++;
            build(i);
        }
    for(int i=1;i<=tot;i++)
        G[i].clear();
    for(int u=1;u<=n;u++)
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(bel[u]==bel[v]) continue;
            G[bel[u]].emplace_back(bel[v]);
        }
    int ans=-1;
    for(int i=1;i<=tot;i++)
        if(!p1[i])
        {
            dfs(i,0);
            int p=p1[i];
            dfs(p,0);
            ans+=d1[p]+1;
        }
    cout<<ans;
    return 0;
}