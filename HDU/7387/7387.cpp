#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=1000005;
int n;
vector<int>G[N];
int lg2[N];
void init(int n=1000000)
{
    lg2[0]=-1;
    for(int i=1;i<=n;i++)
        lg2[i]=lg2[i/2]+1;
    return;
}
int fa[N][20],dep[N];
void dfs(int u,int father)
{
    dep[u]=dep[father]+1;
    fa[u][0]=father;
    for(int i=1;(1<<i)<=n;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
    }
    return;
}
int LCA(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=lg2[n];i>=0;i--)
        if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
    if(u==v) return u;
    for(int i=lg2[n];i>=0;i--)
        if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
int s[N];
void calc(int u,int father)
{
    for(int v:G[u])
    {
        if(v==father) continue;
        calc(v,u);
        s[u]+=s[v];
    }
    return;
}
int p[N],val[N];
void solve()
{
    cin>>n;
    for(int i=2;i<=n;i++)
        cin>>p[i];
    for(int i=2;i<=n;i++)
        cin>>val[i];
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=2;i<=n;i++)
        G[p[i]].emplace_back(i),G[i].emplace_back(p[i]);
    dfs(1,0);
    for(int i=1;i<=n;i++)
        s[i]=0;
    for(int u=2;u<=n;u++)
    {
        int v;
        cin>>v;
        int d=LCA(u,v);
        s[u]++,s[v]++,s[d]-=2;
    }
    calc(1,0);
    int ans=0;
    for(int i=2;i<=n;i++)
        if(val[i]>0&&s[i]>=2) ans++;
    cout<<ans<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    init();
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}