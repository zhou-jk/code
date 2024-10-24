#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005;
int n,k;
int fa[N];
vector<int>G[N];
int dep[N];
int mx[N],b[N];
void dfs(int u,int father)
{
    dep[u]=dep[father]+1;
    mx[u]=dep[u],b[u]=u;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
        if(mx[v]>mx[u]) mx[u]=mx[v],b[u]=b[v];    
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>k;
    k++;
    for(int i=2;i<=n;i++)
    {
        cin>>fa[i];
        G[fa[i]].emplace_back(i);
        G[i].emplace_back(fa[i]);
    }
    dfs(1,0);
    vector<pair<int,int>>v;
    for(int i=2;i<=n;i++)
        v.emplace_back(dep[b[i]]-2*dep[i]+3,i);
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    int ans=2*(n-1);
    static bool vis[N];
    for(int i=0,j=1;i<(int)v.size()&&j<=k;i++)
    {
        auto [w,u]=v[i];
        if(w<=0) break;
        if(vis[b[u]]) continue;
        ans-=w;
        j++;
        vis[b[u]]=true;
    }
    cout<<ans;
    return 0;
}