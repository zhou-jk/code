#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005;
int n,q;
int c[N];
vector<int>G[N];
void dfs(int u,int father)
{
    if(u!=1&&G[u].size()==1) c[u]=1;
    else c[u]=0;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
        c[u]+=c[v];
    }
    return;
}
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    dfs(1,0);
    scanf("%d",&q);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",(long long)c[x]*c[y]);
    }
    return;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}