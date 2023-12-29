#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=500005;
const long long INF=4557430888798830399;
int n;
int a[N];
vector<int>G[N];
long long f[N][4];
long long ans;
void dfs(int u,int father)
{
    f[u][0]=a[u];
    f[u][1]=f[u][2]=f[u][3]=-INF;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
        long long val=max({f[v][0],f[v][1]-a[v],f[v][2]+a[v],f[v][3]});
        if(f[u][3]>-INF) f[u][3]=max(f[u][3],f[u][3]+val);
        if(f[u][2]>-INF) f[u][3]=max(f[u][3],f[u][2]+val);
        if(f[u][1]>-INF) f[u][2]=max(f[u][2],f[u][1]+val);
        f[u][1]=max(f[u][1],val);
    }
    if(f[u][1]>-INF) f[u][1]+=a[u];
    if(f[u][3]>-INF) f[u][3]+=a[u];
    ans=max(ans,max({f[u][0],f[u][1],f[u][2],f[u][3]}));
    return;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    ans=0;
    dfs(1,0);
    cout<<ans<<"\n";
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
