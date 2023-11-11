#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005,M=500005;
int n,m,q;
struct Edge
{
    int to,next;
}edge[M*2];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int dfn[N*2],low[N],Index;
int tot;
stack<int>s;
vector<int>G[N*2];
void tarjan(int u)
{
    dfn[u]=low[u]=++Index;
    s.emplace(u);
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(low[v]==dfn[u])
            {
                tot++;
                G[tot].clear();
                while(!s.empty()&&s.top()!=v)
                {
                    G[tot].emplace_back(s.top());
                    G[s.top()].emplace_back(tot);
                    s.pop();
                }
                G[tot].emplace_back(v);
                G[v].emplace_back(tot);
                s.pop();
                G[tot].emplace_back(u);
                G[u].emplace_back(tot);
            }
        }
        else low[u]=min(low[u],dfn[v]);
    }
    return;
}
int siz[N*2],c[N*2];
int fa[N*2][20],dep[N*2];
void dfs(int u,int father)
{
    dfn[u]=++Index;
    dep[u]=dep[father]+1;
    siz[u]=1;
    if(u<=n) c[u]=1;
    else c[u]=0;
    fa[u][0]=father;
    for(int i=1;(1<<i)<=tot;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
        siz[u]+=siz[v];
        c[u]+=c[v];
    }
    return;
}
int jump(int x,int t)
{
    int u=x;
    for(int i=0;(1<<i)<=tot;i++)
        if(t&(1<<i)) u=fa[u][i];
    return u;
}
void solve()
{
    cin>>n>>m;
    cnt=0;
    for(int i=1;i<=n;i++)
        G[i].clear(),head[i]=0;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add_edge(x,y);
        add_edge(y,x);
    }
    Index=0,tot=n;
    fill(dfn+1,dfn+n+1,0);
    fill(low+1,low+n+1,0);
    while(!s.empty()) s.pop();
    tarjan(1);
    Index=0;
    dfs(1,0);
    cin>>q;
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        int ans=n;
        if(dfn[u]<=dfn[v]&&dfn[v]<=dfn[u]+siz[u]-1) ans-=n-1-c[jump(v,dep[v]-dep[u]-1)];
        else ans-=c[u]-1;
        if(dfn[v]<=dfn[u]&&dfn[u]<=dfn[v]+siz[v]-1) ans-=n-1-c[jump(u,dep[u]-dep[v]-1)];
        else ans-=c[v]-1;
        cout<<ans<<"\n";
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}