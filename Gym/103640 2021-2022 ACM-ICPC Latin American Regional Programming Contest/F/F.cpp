#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=300005;
int n,m;
int vis[N];
vector<int>G[N];
void dfs(int u)
{
    vis[u]=true;
    for(int v:G[u])
    {
        if(vis[v]) continue;
        if(v==n) continue;
        dfs(v);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    dfs(n-1);
    for(int i=1;i<=n;i++)
        if(vis[i]) cout<<"B";
        else cout<<"A";
    return 0;
}