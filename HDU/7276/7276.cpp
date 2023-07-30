#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
const long long INF=4557430888798830399;
int n;
int a[N];
vector<int>G[N];
long long f[N][3];
void dfs(int u,int father)
{
    f[u][0]=0,f[u][1]=INF,f[u][2]=a[u];
    long long sum=0;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
        f[u][0]+=min(f[v][1],f[v][2]);
        f[u][2]+=min({f[v][0],f[v][1],f[v][2]});
        sum+=min(f[v][1],f[v][2]);
    }
    for(int v:G[u])
    {
        if(v==father) continue;
        f[u][1]=min(f[u][1],sum-min(f[v][1],f[v][2])+f[v][2]);
    }
    return;
}
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
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
    printf("%lld\n",min(f[1][1],f[1][2]));
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