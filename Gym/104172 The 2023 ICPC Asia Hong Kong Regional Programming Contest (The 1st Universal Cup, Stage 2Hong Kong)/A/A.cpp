#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005;
int n;
int p[N];
vector<int>G[N];
int f[N];
void dfs(int u,int father)
{
    int cnt=0,mx=0;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
        if(f[v]>mx) mx=f[v],cnt=1;
        else if(f[v]==mx) cnt++;
    }
    if(mx==0) f[u]=1;
    else if(cnt>1) f[u]=mx+1;
    else f[u]=mx;
    return;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=2;i<=n;i++)
        G[p[i]].emplace_back(i),G[i].emplace_back(p[i]);
    dfs(1,0);
    cout<<f[1]<<"\n";
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