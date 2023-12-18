#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=1000005;
const int INF=1061109567;
int n,k;
int c[N];
vector<int>G[N];
int f[N][2];
int ans;
void dfs(int u,int father)
{
    f[u][c[u]&1]=c[u],f[u][(c[u]&1)^1]=-INF;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
        int to[2]={f[u][0],f[u][1]};
        for(int i=0;i<=1;i++)
            if(f[u][i]>=0)
                for(int j=0;j<=1;j++)
                    to[i^j]=max(to[i^j],f[u][i]+f[v][j]);
        f[u][0]=to[0],f[u][1]=to[1];
    }
    if(f[u][k&1]>=k) f[u][0]=f[u][1]=-INF,ans++;
    return;
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>c[i];
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