#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=400005;
const int MOD=1000000007;
int T;
int n;
int a[N],b[N];
int pa[N],pb[N];
vector<int>G[N];
bool vis[N];
void dfs(int u)
{
    vis[u]=true;
    for(int v:G[u])
        if(!vis[v]) dfs(v);
    return;
}
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        pa[a[i]]=i,pb[b[i]]=i;
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<=n;i++)
        G[pa[i]].emplace_back(pb[i]),G[pb[i]].emplace_back(pa[i]);
    for(int i=1;i<=n;i++)
        vis[i]=false;
    int ans=1;
    for(int i=1;i<=n;i++)
        if(!vis[i]&&a[i]!=b[i]) dfs(i),ans=ans*2%MOD;
    printf("%d\n",ans);
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}