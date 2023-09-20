#include<iostream>
#include<cstdio>
#include<cassert>
#include<vector>
#include<unordered_map>
using namespace std;
const int N=100005;
const long long INF=4557430888798830399;
int n;
int a[N];
int tot;
vector<pair<long long,int>>G[N*2];
int match[N];
bool vis[N*2];
void dfs(int u,int father,int pre)
{
    vis[u]=true;
    vector<int>edge;
    for(auto [v,i]:G[u])
    {
        if(v==father) continue;
        if(vis[v]) continue;
        dfs(v,u,i);
    }
    for(auto [v,i]:G[u])
        if(i!=pre)
        {
            if(!match[i]) edge.emplace_back(i);
        }
    if(edge.size()%2==1) edge.emplace_back(pre);
    for(int i=0;i<(int)edge.size();i+=2)
        match[edge[i]]=edge[i+1],match[edge[i+1]]=edge[i];
    return;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    unordered_map<int,int>pos;
    tot=0;
    for(int i=1;i<=n;i++)
    {
        if(!pos.count(i-a[i])) pos[i-a[i]]=++tot;
        if(!pos.count(i+a[i]+INF)) pos[i+a[i]+INF]=++tot;
    }
    for(int i=1;i<=tot;i++)
        G[i].clear(),vis[i]=false;
    for(int i=0;i<=n;i++)
        match[i]=0;
    for(int i=1;i<=n;i++)
        G[pos[i-a[i]]].emplace_back(pos[i+a[i]+INF],i),G[pos[i+a[i]+INF]].emplace_back(pos[i-a[i]],i);
    for(int i=1;i<=tot;i++)
        if(!vis[i])
        {
            dfs(i,0,0);
            if(match[0])
            {
                cout<<"No\n";
                return;
            }
        }
    cout<<"Yes\n";
    for(int i=1;i<=n;i++)
        if(i<match[i]) cout<<i<<" "<<match[i]<<"\n";
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