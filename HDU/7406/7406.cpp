#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=100005;
int n,q;
vector<pair<int,int>>G[N];
int dis[N];
int sum[30][N];
void dfs(int u,int father)
{
    for(auto [v,w]:G[u])
    {
        if(v==father) continue;
        dis[v]=dis[u]^w;
        dfs(v,u);
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
        int u,v,w;
        cin>>u>>v>>w;
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
    }
    dfs(1,0);
    for(int j=0;j<30;j++)
    {
        for(int i=1;i<=n;i++)
            sum[j][i]=sum[j][i-1]+((dis[i]>>j)&1);
    }
    cin>>q;
    while(q--)
    {
        int l,r,x;
        cin>>l>>r>>x;
        long long ans=0;
        for(int j=0;j<30;j++)
        {
            int sr=sum[j][r],sl=sum[j][l-1];
            if((dis[x]>>j)&1) sr=r-sr,sl=l-1-sl;
            ans+=(1ll<<j)*(sr-sl);
        }
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