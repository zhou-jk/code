#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
const int N=1005;
const int MOD=998244353;
int n,m,k;
int a[N];
vector<int>G[N];
unordered_map<int,int>f[N];
int in[N];
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].emplace_back(v);
        in[v]++;
    }
    for(int i=1;i<=n;i++)
        if(k>=a[i]) f[i][k/a[i]]=1;
    queue<int>q;
    for(int i=1;i<=n;i++)
        if(in[i]==0) q.emplace(i);
    int ans=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto [val,num]:f[u])
            ans=(ans+num)%MOD;
        for(int v:G[u])
        {
            for(auto [val,num]:f[u])
                if(val>=a[v]) f[v][val/a[v]]=(f[v][val/a[v]]+num)%MOD;
            in[v]--;
            if(in[v]==0) q.emplace(v);
        }
        f[u].clear();
    }
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