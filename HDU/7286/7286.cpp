#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005;
const int MOD=1000000007;
int n;
int inv[N];
void init(int n=200000)
{
    inv[1]=1;
    for(int i=2;i<=n;i++)
        inv[i]=(long long)(MOD-MOD/i)*inv[MOD%i]%MOD;
    return;
}
vector<int>G[N];
int f[N],g[N],sg[N];
void dfs1(int u,int father)
{
    f[u]=0;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs1(v,u);
        f[u]^=f[v]+1;
    }
    return;
}
void dfs2(int u,int father)
{
    sg[u]=f[u]^g[u];
    for(int v:G[u])
    {
        if(v==father) continue;
        g[v]=(g[u]^f[u]^(f[v]+1))+1;
        dfs2(v,u);
    }
    return;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    dfs1(1,0);
    g[1]=0;
    dfs2(1,0);
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(sg[i]) cnt++;
    int ans=(long long)cnt*inv[n]%MOD;
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