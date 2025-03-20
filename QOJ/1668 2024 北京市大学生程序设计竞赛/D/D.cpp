#include<bits/stdc++.h>
using namespace std;
constexpr int N=200005;
int n,m,q;
int b[N];
vector<int>G[N];
int dfn[N],Index;
int mn[N][20],lg2[N];
int dep[N];
void dfs(int u,int father)
{
    dep[u]=dep[father]+1;
    dfn[u]=++Index;
    mn[Index][0]=father;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
    }
    return;
}
int lca(int u,int v)
{
    if(u==v) return u;
    u=dfn[u],v=dfn[v];
    if(u>v) swap(u,v);
    u++;
    int d=lg2[v-u+1];
    if(dfn[mn[u][d]]<dfn[mn[v-(1<<d)+1][d]]) return mn[u][d];
    else return mn[v-(1<<d)+1][d];
}
int dis(int a,int b)
{
    return dep[a]+dep[b]-dep[lca(a,b)]*2;
}
void init_lca(int n)
{
    lg2[0]=-1;
    for(int i=1;i<=n;i++)
        lg2[i]=lg2[i/2]+1;
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            if(dfn[mn[i][j-1]]<dfn[mn[i+(1<<(j-1))][j-1]]) mn[i][j]=mn[i][j-1];
            else mn[i][j]=mn[i+(1<<(j-1))][j-1];
    return;
}
bool check(int a,int b,int c)
{
    if(a==0||c==0) return true;
    return dis(a,b)+dis(b,c)!=dis(a,c);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>q;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    for(int i=1;i<=m;i++)
        cin>>b[i];
    dfs(1,0);
    init_lca(n);
    int ans=1;
    for(int i=1;i<m;i++)
        if(check(b[i-1],b[i],b[i+1])) ans++;
    while(q--)
    {
        int i,w;
        cin>>i>>w;
        if(i+2<=m)
        {
            if(check(b[i],b[i+1],b[i+2])) ans--;
        }
        if(i+1<=m)
        {
            if(check(b[i-1],b[i],b[i+1])) ans--;
        }
        if(i-1>=1)
        {
            if(check(b[i-2],b[i-1],b[i])) ans--;
        }
        b[i]=w;
        if(i+2<=m)
        {
            if(check(b[i],b[i+1],b[i+2])) ans++;
        }
        if(i+1<=m)
        {
            if(check(b[i-1],b[i],b[i+1])) ans++;
        }
        if(i-1>=1)
        {
            if(check(b[i-2],b[i-1],b[i])) ans++;
        }
        cout<<ans<<"\n"; 
    }
    return 0;
}