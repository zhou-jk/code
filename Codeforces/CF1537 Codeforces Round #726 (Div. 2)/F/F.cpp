#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005;
int T;
int n,m;
int v[N],t[N];
vector<int>G[N];
int col[N];
bool flag;
void dfs(int u,int color)
{
    if(col[u]!=-1)
    {
        if(col[u]!=color) flag=true;
        return;
    }
    else col[u]=color;
    for(int v:G[u])
        dfs(v,color^1);
    return;
}
void solve()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    fill(col+1,col+n+1,-1);
    flag=false;
    for(int i=1;i<=n;i++)
        if(col[i]==-1) dfs(i,0);
    if(!flag)
    {
        long long s0=0,s1=0;
        for(int i=1;i<=n;i++)
            if(col[i]==0) s0+=t[i]-v[i];
            else s1+=t[i]-v[i];
        if(s0!=s1) printf("NO\n");
        else printf("YES\n");
        return;
    }
    long long sum=0;
    for(int i=1;i<=n;i++)
        sum+=t[i]-v[i];
    if(sum&1) printf("NO\n");
    else printf("YES\n");
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}